// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RLCharacter.generated.h"

UCLASS(Blueprintable)
class SHOOTERGAME_API ARLCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ARLCharacter();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RL Character")
		float health = 100;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RL Character")
		bool hasFlag = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RL Character")
		bool hearsNoise = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RL Character")
		bool seesEnemy = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RL Character")
		bool bumps = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RL Character")
		bool takesDamage = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RL Character")
		bool moves = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RL Character")
		float enemyDistance = 0.0;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "RL Character")
		bool isDead = false;

	virtual void SetIfDead();

	UFUNCTION(BlueprintCallable, Category = "RL Character")
		virtual void CalcHealth(float delta);

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent & PropertyChangedEvent) override;
#endif

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
