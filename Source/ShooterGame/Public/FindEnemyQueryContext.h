// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryContext.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_Actor.h"
#include "MLCharacter.h"
#include "RLController.h"
#include "FindEnemyQueryContext.generated.h"

/**
 * 
 */

 UCLASS()
class SHOOTERGAME_API UFindEnemyQueryContext : public UEnvQueryContext
{
 	GENERATED_BODY()

	virtual void ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& QueryContextData) const override;
};
