// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Runtime/Engine/Classes/Components/SphereComponent.h"
#include "Runtime/Engine/Classes/GameFramework/ProjectileMovementComponent.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AOBullet.generated.h"

UCLASS()
class TEAM4GAME_API AAOBullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// class constructor
	// takes no variables
	// returns reference to new bullet object
	AAOBullet();

protected:
	// Not used. Called when the game starts by UE4.
	// tales no variables
	// returns no variabl
	virtual void BeginPlay() override;

	// Function that initializes the projectile's velocity in the shoot direction
	// takes a FVector ShootDirection as input (this should be direction player is facing)
	// returns no variable
	void FireInDirection(const FVector& ShootDirection);

public:	
	// Not used. Called every frame by UE4.
	// Input var DeltaTime is the time difference (float) between current frame and last frame
	// Returns no variable.
	virtual void Tick(float DeltaTime) override;

	// sphere collision component used to figure out what bullet has collided with
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
		USphereComponent* CollisionComponent;
	
	// bullet mesh component that gives bullet a visible shape and color
	UStaticMeshComponent* Mesh;

	// Projectile movement component used to move bullet
	UPROPERTY(VisibleAnywhere, Category = Movement)
		UProjectileMovementComponent* ProjectileMovementComponent;
};
