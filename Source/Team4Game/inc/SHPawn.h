// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AOWeaponManager.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/SphereComponent.h"
#include "Camera/CameraComponent.h"
#include "SHPawn.generated.h"

UCLASS()
class TEAM4GAME_API ASHPawn : public APawn
{
	GENERATED_BODY()
    
    //This allows the mesh to be set within Unreal
    UPROPERTY(EditDefaultsOnly)
    UStaticMeshComponent* mSphereVisual;
    
    //This allows the mesh to be set within Unreal
    UPROPERTY(EditDefaultsOnly)
    UStaticMeshComponent* mGunVisual;
    
    UPROPERTY(EditAnywhere)
    UAOWeaponManager* weaponManager;
    
    UPROPERTY(EditAnywhere)
    USpringArmComponent* SpringArm;
    
    UPROPERTY(EditAnywhere)
    UCameraComponent* Camera;
    
    UPROPERTY(EditAnywhere)
    bool mTest = false;
    
    UPROPERTY(EditAnywhere)
    bool mStress = false;
    
    UPROPERTY(EditAnywhere)
    USphereComponent* SphereComponent;
    
    
public:
	// Sets default values for this pawn's properties
	ASHPawn();

protected:
    // Called when the game starts or when spawned;
	virtual void BeginPlay() override;
public:	
    // Called every frame; sets position of player
	virtual void Tick(float DeltaTime) override;
    bool GetTest();
    bool GetStress();
    //Move left/right
    void Move_XAxis(float AxisValue);
    //Move forward/backward
    void Move_YAxis(float AxisValue);
    //Request that a bullet is shot
    void Shoot();
    void LookDir(FVector pos);
    void LookMouse(FVector pos);

private:
    //Input variables
    FVector CurrentVelocity;
    
	
};
