// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MAMap.h"
#include "DSEnemy.h"
#include "CHGameManager.generated.h"

/**
 * 
 */
UCLASS()
class TEAM4GAME_API ACHGameManager : public AGameStateBase
{
	GENERATED_BODY()

public:
	void beginPlay();
private:
	void generateMap();
	void spawnEnemies();
	void initiateAssets();
};