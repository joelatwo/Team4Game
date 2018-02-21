// Fill out your copyright notice in the Description page of Project Settings.

#include "DSEnemy.h"


// Sets default values
ADSEnemy::ADSEnemy()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    

}

// Called when the game starts or when spawned
void ADSEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADSEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADSEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

