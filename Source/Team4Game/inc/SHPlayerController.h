// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DSEnemy.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "SHPlayerController.generated.h"
/**
 * Recieves input and tells the player pawn to move
 */
UCLASS()
class TEAM4GAME_API ASHPlayerController : public APlayerController
{
	GENERATED_BODY()
    
public:
    //Set to call tick every frame
    ASHPlayerController();
    /**
     * Called every frame. Sets position of player. This is called automatically.
     * @param DeltaTime - the amount of time the last frame took
     */
    virtual void Tick(float DeltaTime) override;
    /**
     * Sets whether testing mode should be active
     * @param TestValue - the value to set bTest to
     */
    void SetTest(bool TestValue);
    /**
     * Sets whether stress mode should be active
     * @param StressValue - the value to set bStress to
     */
    void SetStress(bool StressValue);
    
private:
    //Sets up the handling of input
    virtual void SetupInputComponent() override;
    //Whether test mode should be turned on
    bool bTest = false;
    //Whether stress mode should be turned on
    bool bStress = false;
    //The enemy being targeted during test mode
    ACharacter* target;
    //The pawn moves randomly every frame
    void Stress();
    //During test mode, find the nearest enemy and target it
    void AIKill();
    //During test mode, aim at the target and shoot
    void AimTarget();
    //tells possessed pawn (player) to move left/right
    void MovePawnX(float AxisValue);
    //Tells player pawn to move forward/backward
    void MovePawnY(float AxisValue);
    //Tells player pawn to shoot
    void Shoot();
    //Look in the direction of the mouse
    void LookDir();
	
};
