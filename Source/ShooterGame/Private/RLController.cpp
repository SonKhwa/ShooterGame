// Fill out your copyright notice in the Description page of Project Settings.


#include "RLController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "MLCharacter.h"

void ARLController::OnPerceptionUpdated(const TArray<AActor*>& UpdActors)
{
	for (AActor* Actor : UpdActors)
	{
		if (Actor->IsA<ARLCharacter>() && !GetSeenPawn())
		{
			BlackboardComponent->SetValueAsObject(BlackboardEnemyKey, Actor);
			return;
		}
	}
	BlackboardComponent->SetValueAsObject(BlackboardEnemyKey, nullptr);
}

ARLController::ARLController()
{
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(FName("BehaviorComp"));
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(FName("BlackboardComp"));
	AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(FName("PerceptionComp"));
	Sight = CreateDefaultSubobject<UAISenseConfig_Sight>(FName("Sight Config"));

	Sight->SightRadius = 1000.f;
	Sight->LoseSightRadius = 1500.f;
	Sight->PeripheralVisionAngleDegrees = 130.f;

	Sight->DetectionByAffiliation.bDetectEnemies = true;
	Sight->DetectionByAffiliation.bDetectFriendlies = true;
	Sight->DetectionByAffiliation.bDetectNeutrals = true;

	AIPerceptionComponent->ConfigureSense(*Sight);
}

void ARLController::OnPossess(APawn* InPawn)
{
	Super::Possess(InPawn);

	if (BehaviorTree)
	{
		BlackboardComponent->InitializeBlackboard(*BehaviorTree->BlackboardAsset);
		BehaviorTreeComponent->StartTree(*BehaviorTree);
	}
	AIPerceptionComponent->OnPerceptionUpdated.AddDynamic(this, &ARLController::OnPerceptionUpdated);
}

AActor* ARLController::GetSeenPawn()
{
	UObject* object = BlackboardComponent->GetValueAsObject(BlackboardEnemyKey);
	return object
	? Cast<AActor>(object)
	: nullptr;
}
