// Fill out your copyright notice in the Description page of Project Settings.

#include "../../inc/SHPlayerController.h"
#include "../../inc/SHPawn.h"
#include "../../inc/SHPlayerCameraManager.h"
#include "EngineUtils.h"
ASHPlayerController::ASHPlayerController() {
    PrimaryActorTick.bCanEverTick = true;    //PlayerCameraManagerClass = ASHPlayerCameraManager;
    
    //PlayerCameraManagerClass = ASHPlayerCameraManager::StaticClass();
    //if (GetPawn())
    //    PlayerCameraManager->SetViewTarget(GetPawn());
    //PlayerCameraManager->SetViewTarget(GetPawn(),FViewTargetTransitionParams());
}

void ASHPlayerController::BeginPlay() {
    Super::BeginPlay();
    if (GetPawn()) {
        test = Cast<ASHPawn>(this->GetPawn())->GetTest();
    }
}

void ASHPlayerController::AIKill() {
    if (GetPawn() == NULL) return;
    float dist = -1;
    for (TActorIterator<ADSEnemy> ActorItr(GetWorld()); ActorItr; ++ActorItr)
    {
        float tempDist = GetPawn()->GetDistanceTo(*ActorItr);
        if (dist == -1 ||  tempDist < dist) {
            dist = tempDist;
            target = *ActorItr;
        }
    }
}

void ASHPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if (!test)
        LookDir();
    else {
        if (target == NULL) AIKill();
        if (target != NULL) AimTarget();
    }
}

void ASHPlayerController::SetupInputComponent() {
    Super::SetupInputComponent();
    if (!test) {
        InputComponent->BindAxis("MoveX", this, &ASHPlayerController::MovePawnX);
        InputComponent->BindAxis("MoveY", this, &ASHPlayerController::MovePawnY);
        InputComponent->BindAction("Shoot", IE_Pressed, this, &ASHPlayerController::Shoot);
        
    }
}

void ASHPlayerController::MovePawnX(float AxisValue) {
    Cast<ASHPawn>(this->GetPawn())->Move_XAxis(AxisValue);
    
}

void ASHPlayerController::MovePawnY(float AxisValue) {
    Cast<ASHPawn>(this->GetPawn())->Move_YAxis(AxisValue);
}

void ASHPlayerController::Shoot() {
    Cast<ASHPawn>(this->GetPawn())->Shoot();
}

void ASHPlayerController::AimTarget() {
    Cast<ASHPawn>(this->GetPawn())->LookDir(target->GetActorLocation());
    Shoot();
}

void ASHPlayerController::LookDir() {
    FVector worldPos, dir;
    this->DeprojectMousePositionToWorld(worldPos, dir);
    //UE_LOG(LogTemp, Warning, TEXT("worldpos: %s"), *worldPos.ToString());
    //UE_LOG(LogTemp, Warning, TEXT("dir: %s"), *dir.ToString());
    Cast<ASHPawn>(this->GetPawn())->LookDir(dir);
}
