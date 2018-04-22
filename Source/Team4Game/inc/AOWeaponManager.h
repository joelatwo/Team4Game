// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "AOWeaponManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TEAM4GAME_API UAOWeaponManager : public USceneComponent
{
	GENERATED_BODY()

public:	
	// class constructor
	// takes no variables
	// returns reference to new weapon manager object
	UAOWeaponManager();

protected:
	// Not used. Called when the game starts by UE4.
	// tales no variables
	// returns no variable
	virtual void BeginPlay() override;

public:	
	// Not used. Called every frame by UE4.
	// Input: 
	//		DeltaTime is the time difference (float) between current frame and last frame
	//		TickType is the kind of tick this is (e.g. are we paused, or 'simulating' in editor)
	//		ThisTickFunction is an internal tick function struct that caused this function to run
	// Returns no variable.
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Shoots currently equiped gun in proper direction.
	// Takes no variables.
	// Returns no variables.
	UFUNCTION()
	void Shoot();
	
};
