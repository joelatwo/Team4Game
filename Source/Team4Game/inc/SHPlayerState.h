// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "SHPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class TEAM4GAME_API ASHPlayerState : public APlayerState
{
	GENERATED_BODY()
	
private:
    float Health;
public:
    //get player health
    float GetHealth();
    //set the player health; always returns true
    bool SetHealth(float h);
    //subtract an amount from the player health; return true if player dead, false if not dead
    bool DoDamage(float d);
	
	
};
