// Fill out your copyright notice in the Description page of Project Settings.

#include "../../inc/SHPlayerController.h"
#include "../../inc/SHPawn.h"
#include "EngineUtils.h"

ASHPlayerController::ASHPlayerController()
{
    //Call Tick() every frame
    PrimaryActorTick.bCanEverTick = true;
}

void ASHPlayerController::Stress()
{
    MovePawnY(FMath::FRandRange(-1.0,1.0));
    MovePawnX(FMath::FRandRange(-1.0,1.0));
    
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
    //If stress mode, call Stress() to move pawn randomly
    if (bStress)
    {
        Stress();
    }
    //If not in test mode, make pawn look at mouse
    if (!bTest)
    {
        LookDir();
    }
    else
    {
        //Find a target
        AIKill();
        //If a target has been found, check to make sure it's valid
        if (target)
        {
            if (target->IsPendingKill() || !target->IsValidLowLevel())
            {
                target = NULL;
            }
        }
        //Aim at the target and shoot at it, if a target is available
        if (target != NULL) AimTarget();
    }
}

void ASHPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    //If testing mode is on, then player input is not accepted, so don't set it up
    if (!bTest)
    {
        //Set up movement and shooting input
        InputComponent->BindAxis("MoveX", this, &ASHPlayerController::MovePawnX);
        InputComponent->BindAxis("MoveY", this, &ASHPlayerController::MovePawnY);
        InputComponent->BindAction("Shoot", IE_Pressed, this, &ASHPlayerController::Shoot);
    }
}

void ASHPlayerController::MovePawnX(float AxisValue)
{
    //Ask the pawn to move left/right
    if (GetPawn())
        {
            Cast<ASHPawn>(this->GetPawn())->Move_XAxis(AxisValue);
        }
}

void ASHPlayerController::MovePawnY(float AxisValue)
{
    if (GetPawn())
    {
        //Ask the pawn to move up/down
        Cast<ASHPawn>(this->GetPawn())->Move_YAxis(AxisValue);
        
    }
}

void ASHPlayerController::Shoot()
{
    if (GetPawn())
    {
        //Ask the pawn to shoot
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
        //Find the mouse position and have the pawn look at it
        FVector worldPos, dir;
        this->DeprojectMousePositionToWorld(worldPos, dir);
        Cast<ASHPawn>(this->GetPawn())->LookMouse(dir);
    }
}
