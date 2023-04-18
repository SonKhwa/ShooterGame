// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MapConverting.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERGAME_API UMapConverting : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

		UFUNCTION(BlueprintCallable, Category = "MapConverting")
		static FString ConvertMapToString(TMap<FString, float> Map);

	UFUNCTION(BlueprintCallable, Category = "MapConverting")
		static TMap<FString, float> ConvertStringToMap(FString Data);
};
