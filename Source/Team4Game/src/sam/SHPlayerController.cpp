// Fill out your copyright notice in the Description page of Project Settings.

#include "../../inc/SHPlayerController.h"
#include "../../inc/SHPawn.h"
ASHPlayerController::ASHPlayerController() {
    
}

void ASHPlayerController::BeginPlay() {
}

void ASHPlayerController::SetupInputComponent() {
    Super::SetupInputComponent();
    InputComponent->BindAxis("MoveX", this, &ASHPlayerController::MovePawnX);
    InputComponent->BindAxis("MoveY", this, &ASHPlayerController::MovePawnY);
}

void ASHPlayerController::MovePawnX(float AxisValue) {
   Cast<ASHPawn>(this->GetPawn())->Move_XAxis(AxisValue);
}

void ASHPlayerController::MovePawnY(float AxisValue) {
    Cast<ASHPawn>(this->GetPawn())->Move_YAxis(AxisValue);
}
