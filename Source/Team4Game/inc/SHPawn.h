// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AOWeaponManager.h"
#include "SHPlayerState.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/SphereComponent.h"
#include "Camera/CameraComponent.h"
#include "SHPawn.generated.h"

UCLASS()
class TEAM4GAME_API ASHPawn : public APawn
{
	GENERATED_BODY()
    
    //An inherited Unreal function used as a delagate for the OnHit event.
    //It is called when the pawn's sphere component is hit.
    //The parameters are used by the event and do not need to be provided by programmers.
    UFUNCTION()
    void OnHit(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
    
public:
    // Creates the pawn's components and sets their default values
    ASHPawn();
    /**
     * Prints a description string. Shamelessly used for static binding.
     */
    void Description();
    /**
     * Called every frame. Sets position of player. This is called automatically.
     * @param DeltaTime - the amount of time the last frame took
     */
	virtual void Tick(float DeltaTime) override;
    /**
     * Called by player controller to move left/right
     * @param AxisValue - a value -1 - 1 that specifies how much to move
     */
    void Move_XAxis(float AxisValue);
    /**
     * Called by player controller to move up/down
     * @param AxisValue - a value -1 - 1 that specifies how much to move
     */
    void Move_YAxis(float AxisValue);
    /**
     * Requests that a bullet is shot by the weapon manager.
     * Virutal so that it can be overwritted by subclasses to add additional wepain functionality.
     */
    virtual void Shoot();
    /**
     * Rotates pawn to look at a specific point. This is used in testing mode to look at the targeted enemy.
     * @param Position - a vector specifying the point to look at
     */
    void LookDir(FVector Position);
    /**
     * Rotates pawn to look at the mouse position.
     * @param Direction - the direction of the mouse
     */
    void LookMouse(FVector Direction);
    //The object that movement requests are delegated to; performs the actual movement of the pawn
    class USHPawnMovementComponent* MovementComponent;
    class SHPlayerState* PS;
    
protected:
    //The object that handles shooting; protected so it can be repositioned by subclasses
    UAOWeaponManager* WeaponManager;
    
private:
    //The amount of time the player is invincible after taking damage
    float HitCooldown = 1;
    //A counter for how much time has passed since the player took damage
    float HitCounter = 0;
    
	
};
