// Fill out your copyright notice in the Description page of Project Settings.

#include "FindEnemyQueryContext.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_Actor.h"
#include "RLCharacter.h"
#include "RLController.h"

void UFindEnemyQueryContext::ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& QueryContextData) const
{
	Super::ProvideContext(QueryInstance, QueryContextData);

	//Get the owner of this request and pass it to the actor. Then get the actor controller and apply our AIController to it
	ARLController* AIController = Cast<ARLController>(Cast<AActor>(QueryInstance.Owner.Get())->GetInstigatorController());

	if (AIController && AIController->GetSeenPawn())
		UEnvQueryItemType_Actor::SetContextHelper(QueryContextData, AIController->GetSeenPawn());
}
