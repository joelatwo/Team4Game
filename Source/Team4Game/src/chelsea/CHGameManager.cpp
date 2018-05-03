// Fill out your copyright notice in the Description page of Project Settings.

#include "../../inc/CHGameManager.h"


void ACHGameManager::beginPlay()
{
	generateMap();
	spawnEnemies();
	initiateAssets();
}

void ACHGameManager::generateMap()
{
	AMAMap Map;
	//Map.AMAMap::AMAMap();		// call map generation	
}

void ACHGameManager::spawnEnemies()
{
	//ADSEnemy Enemy1;
	//ADSEnemy Enemy2;
	//Enemy1.ADSEnemy::ADSEnemy();
	//Enemy2.ADSEnemy::ADSEnemy();
}

void ACHGameManager::initiateAssets()
{
	// start sound and graphics
}
