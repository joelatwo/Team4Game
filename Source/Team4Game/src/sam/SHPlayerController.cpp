// Fill out your copyright notice in the Description page of Project Settings.

#include "../../inc/SHPlayerController.h"
#include "../../inc/SHPawn.h"
#include "../../inc/SHPlayerCameraManager.h"
#include "EngineUtils.h"

ASHPlayerController::ASHPlayerController()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ASHPlayerController::BeginPlay()
{
    Super::BeginPlay();
}

void ASHPlayerController::Stress()
{
    MovePawnY(FMath::FRandRange(-1.0,1.0));
    MovePawnX(FMath::FRandRange(-1.0,1.0));
    //if (!test)
    //    Shoot();
    
}

void ASHPlayerController::SetStress(bool b)
{
    bStress = b;
}

void ASHPlayerController::SetTest(bool b)
{
    bTest = b;
}

void ASHPlayerController::AIKill() {
    if (GetPawn() == NULL) return;
    float dist = -1;
    for (TActorIterator<ACharacter> ActorItr(GetWorld()); ActorItr; ++ActorItr)
    {
        if (!(*ActorItr)->IsPendingKill() && (*ActorItr)->IsValidLowLevel())
        {
            float tempDist = GetPawn()->GetDistanceTo(*ActorItr);
            //UE_LOG(LogTemp, Warning, TEXT("worldpos: %s"), *ActorItr->GetActorLabel());
            if (dist == -1 ||  tempDist < dist)
            {
                dist = tempDist;
                target = *ActorItr;
            }
        }
    }
}

void ASHPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if (bStress)
    {
        Stress();
    }
    if (!bTest)
    {
        LookDir();
    }
    else
    {
        if (target)
        {
            if (target->IsPendingKill() || !target->IsValidLowLevel())
            {
                target = NULL;
            }
        }
        AIKill();
        if (target != NULL) AimTarget();
    }
}

void ASHPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    if (!bTest)
    {
        InputComponent->BindAxis("MoveX", this, &ASHPlayerController::MovePawnX);
        InputComponent->BindAxis("MoveY", this, &ASHPlayerController::MovePawnY);
        InputComponent->BindAction("Shoot", IE_Pressed, this, &ASHPlayerController::Shoot);
    }
}

void ASHPlayerController::MovePawnX(float AxisValue)
{
    if (GetPawn())
        {
            Cast<ASHPawn>(this->GetPawn())->Move_XAxis(AxisValue);
        }
}

void ASHPlayerController::MovePawnY(float AxisValue)
{
    if (GetPawn())
    {
        Cast<ASHPawn>(this->GetPawn())->Move_YAxis(AxisValue);
        
    }
}

void ASHPlayerController::Shoot()
{
    if (GetPawn())
    {
        Cast<ASHPawn>(this->GetPawn())->Shoot();
    }
}

void ASHPlayerController::AimTarget()
{
    if (GetPawn())
        {
            Cast<ASHPawn>(this->GetPawn())->LookDir(target->GetActorLocation());
            Shoot();
            
        }
}

void ASHPlayerController::LookDir()
{
    if (GetPawn())
    {
        FVector worldPos, dir;
        this->DeprojectMousePositionToWorld(worldPos, dir);
        Cast<ASHPawn>(this->GetPawn())->LookMouse(dir);
    }
}
