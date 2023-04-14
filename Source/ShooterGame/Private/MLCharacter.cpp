// Fill out your copyright notice in the Description page of Project Settings.


#include "MLCharacter.h"

// Sets default values
AMLCharacter::AMLCharacter()
{
 	// Turn off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMLCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMLCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMLCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

