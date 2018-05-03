// Fill out your copyright notice in the Description page of Project Settings.

#include "../../inc/SHSpawner.h"
#include "../../inc/SHPawn.h"
#include "../../inc/MAMap.h"
#include "../../inc/SHPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "../../inc/SHPawnTwoGuns.h"

ASHSpawner* ASHSpawner::Instance = 0;


ASHSpawner::~ASHSpawner()
{
    if (Instance == this)
    {
        Instance = NULL;
    }
}

// Called when the game starts
void ASHSpawner::BeginPlay()
{
    Super::BeginPlay();
    
    /**
     * Set up the singleton. I cannot use the traditional lazily constructed method.
     * Since this is an Actor class, it has to be created using the SpawnObject function
     * or by being dragged into the editor.
     * This means that you can just create it with new and that it always has to
     * be allowed to be created or crashing happens.
     * Thus, if the instance variable is null or invalid, set the instance to this object.
     * Otherwise, destroy this object.
     */
    if (!Instance || Instance->IsPendingKill() || !Instance->IsValidLowLevel())
    {
        Instance = this;
    }
    else
    {
        Destroy();
        return;
    }
    //Set the test and stress values in the player controller
    ASHPlayerController* controller = Cast<ASHPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
    if (controller) {
        controller->SetTest(bTest);
        controller->SetStress(bStress);
    }
    //Spawn the map
    Map = GetWorld()->SpawnActor<AMAMap>(FVector(-1250,-1250,100),FRotator(0,0,0),FActorSpawnParameters());
    //Spawn the pawn.
    if (bSpawnDefaultPawn)
    {
        SpawnDefaultPawn();
    }
    else
    {
        SpawnTwoGunPawn();
    }
}

bool ASHSpawner::GetStress()
{
    return bStress;
}

bool ASHSpawner::GetTest()
{
    return bTest;
}

void ASHSpawner::SetStress(bool StressValue)
{
    bStress = StressValue;
    ASHPlayerController* controller = Cast<ASHPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
    if (controller) {
        controller->SetStress(StressValue);
    }
}

void ASHSpawner::SetTest(bool TestValue)
{
    bTest = TestValue;
    ASHPlayerController* controller = Cast<ASHPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
    if (controller) {
        controller->SetTest(TestValue);
    }
}

void ASHSpawner::NewMap()
{
    Map->Destroy();
    Map = GetWorld()->SpawnActor<AMAMap>(FVector(-1250,-1250,100),FRotator(0,0,0),FActorSpawnParameters());
}

void ASHSpawner::SpawnPawn()
{
    //Spawn the pawn.
    if (bSpawnDefaultPawn)
    {
        SpawnDefaultPawn();
    }
    else
    {
        SpawnTwoGunPawn();
    }
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
    return Instance;
}

