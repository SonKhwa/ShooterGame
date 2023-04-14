// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "RLCharacter.h"
#include "RLController.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERGAME_API ARLController : public AAIController
{
	GENERATED_BODY()

private:
	UBlackboardComponent* BlackboardComponent;

	UBehaviorTreeComponent* BehaviorTreeComponent;

	UAISenseConfig_Sight* Sight;

	const FName BlackboardEnemyKey = FName("Enemy");

	UFUNCTION()
		void OnPerceptionUpdated(const TArray<AActor*>& UpdActors);

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UBehaviorTree* BehaviorTree;

	UPROPERTY(VisibleAnywhere)
		UAIPerceptionComponent* AIPerceptionComponent;

public:

	ARLController();

	virtual void OnPossess(APawn* InPawn) override;

	AActor* GetSeenPawn();
};
