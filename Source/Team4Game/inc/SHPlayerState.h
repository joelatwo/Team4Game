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
    float health;
public:
    float getHealth();
    bool setHealth(float h);
	
	
};
