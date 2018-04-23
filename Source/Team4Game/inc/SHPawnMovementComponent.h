// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PawnMovementComponent.h"
#include "SHPawnMovementComponent.generated.h"

/**
 * Handles moving the player pawn
 */
UCLASS()
class TEAM4GAME_API USHPawnMovementComponent : public UPawnMovementComponent
{
	GENERATED_BODY()
	
	
public:
    /**
     * Every frame, check to see if movement should occur.
     * This function is called by the engine, so a programmer does not need to call with parameters.
     */
    virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
    
	
};
