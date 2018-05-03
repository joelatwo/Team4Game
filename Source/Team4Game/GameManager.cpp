// Fill out your copyright notice in the Description page of Project Settings.

#include "GameManager.h"
#include "inc/SHPlayerState.h"
#include "inc/SHPawn.h"
#include "Kismet/GameplayStatics.h"
#include "inc/DSEnemy.h"


// Sets default values for this component's properties
UGameManager::UGameManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGameManager::BeginPlay()
{
	Super::BeginPlay();

    controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	
}

void UGameManager::RespawnPlayer()
{
    ASHPawn* pawn = Cast<ASHPawn>(controller->GetPawn());
    pawn->SetActorLocation(FVector(710,30,250));
    pawn->PS->SetLife(1000);
    ADSEnemy::ResetScore();
}

void UGameManager::SpawnPlayer()
{
    
}

// Called every frame
void UGameManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    

    ASHPawn* pawn = Cast<ASHPawn>(controller->GetPawn());
    float health = pawn->PS->GetLife();
    if (health <= 0)
    {
        RespawnPlayer();
    }
}

