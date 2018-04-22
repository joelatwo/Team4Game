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
    
    //This allows the mesh to be set within Unreal
   // UPROPERTY(EditDefaultsOnly)
    //UStaticMeshComponent* mSphereVisual;
    
    //This allows the mesh to be set within Unreal
    //UPROPERTY(EditAnywhere)
    //UStaticMeshComponent* mGunVisual;
    
    //UPROPERTY(EditAnywhere)
    //UAOWeaponManager* WeaponManager;
    
    //UPROPERTY(EditAnywhere)
    //USpringArmComponent* SpringArm;
    
    //UPROPERTY(EditAnywhere)
    //UCameraComponent* Camera;
    
    UFUNCTION()
    void OnHit(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
    
    //UPROPERTY(EditAnywhere)
    //USphereComponent* SphereComponent;
    
    
public:
	// Sets default values for this pawn's properties
	ASHPawn();

protected:
    // Called when the game starts or when spawned;
	virtual void BeginPlay() override;
    UAOWeaponManager* WeaponManager;
public:	
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
     * Requests that a bullet is shot
     */
    virtual void Shoot();
    /**
     * Looks at a specified point
     * @param pos - a vector specifying the point to look at
     */
    void LookDir(FVector pos);
    /**
     * Look at the mouse
     * @param pos - the direction of the mouse
     */
    void LookMouse(FVector pos);
    //Reference to the movement component
    class USHPawnMovementComponent* MovementComponent;
    class SHPlayerState* PlayerState;
    
    
private:
    //Input variables
    FVector CurrentVelocity;
    float hitCooldown = 1;
    float hitCounter = 0;
    
	
};
