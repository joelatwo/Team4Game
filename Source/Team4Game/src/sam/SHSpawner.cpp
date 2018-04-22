// Fill out your copyright notice in the Description page of Project Settings.

#include "../../inc/SHSpawner.h"
#include "../../inc/SHPawn.h"
#include "../../inc/MAMap.h"
#include "../../inc/SHPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "../../inc/SHPawnTwoGuns.h"

ASHSpawner* ASHSpawner::instance = 0;

// Sets default values for this component's properties
ASHSpawner::ASHSpawner()
{
    
}


// Called when the game starts
void ASHSpawner::BeginPlay()
{
    Super::BeginPlay();
    
    if (!instance)
    {
        instance = this;
    }
    else
    {
        Destroy();
    }
    ASHPlayerController* controller = Cast<ASHPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
    if (controller) {
        controller->SetTest(mTest);
        controller->SetStress(mStress);
    }
    AMAMap *LevelMap = GetWorld()->SpawnActor<AMAMap>(FVector(-1250,-1250,100),FRotator(0,0,0),FActorSpawnParameters());
    if (bSpawnDefaultPawn)
    {
        SpawnDefaultPawn();
    }
    else
    {
        SpawnTwoGunPawn();
    }
}

bool ASHSpawner::GetStress(bool b)
{
    return mStress;
}

bool ASHSpawner::GetTest(bool b)
{
    return mTest;
}

void ASHSpawner::SetStress(bool b)
{
    mStress = b;
}

void ASHSpawner::SetTest(bool b)
{
    mTest = b;
}

void ASHSpawner::SpawnDefaultPawn()
{
    APlayerController* controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    APawn* pawn = controller->GetPawn();
    controller->UnPossess();
    pawn->Destroy();
    ASHPawn* newPawn = GetWorld()->SpawnActor<ASHPawn>(FVector(710,30,250),FRotator(0,0,0),FActorSpawnParameters());
    controller->SetPawn(newPawn);
    controller->Possess(newPawn);
}

void ASHSpawner::SpawnTwoGunPawn()
{
    APlayerController* controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    APawn* pawn = controller->GetPawn();
    controller->UnPossess();
    pawn->Destroy();
    ASHPawnTwoGuns* newPawn = GetWorld()->SpawnActor<ASHPawnTwoGuns>(FVector(710,30,250),FRotator(0,0,0),FActorSpawnParameters());
    controller->SetPawn(newPawn);
    controller->Possess(newPawn);
}

ASHSpawner* ASHSpawner::GetInstance()
{
    return instance;
}

