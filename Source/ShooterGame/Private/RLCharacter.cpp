// Fill out your copyright notice in the Description page of Project Settings.


#include "RLCharacter.h"

// Sets default values
ARLCharacter::ARLCharacter()
{
 	// Turn off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARLCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ARLCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARLCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ARLCharacter::SetIfDead()
{
	isDead = health <= 0;
}

void ARLCharacter::CalcHealth(float healingValue)
{
	health += healingValue;
	SetIfDead();
}

// Implement PostEditChangeProperty
#if WITH_EDITOR
void ARLCharacter::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	isDead = false;
	health = 100;
	Super::PostEditChangeProperty(PropertyChangedEvent);
	SetIfDead();
}
#endif

