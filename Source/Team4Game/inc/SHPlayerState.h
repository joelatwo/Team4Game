// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class TEAM4GAME_API SHPlayerState
{
	
private:
    float Health;
public:
    SHPlayerState();
    ~SHPlayerState();
    //get player health
    float GetHealth();
    //set the player health; always returns true
    bool SetHealth(float h);
    //subtract an amount from the player health; return true if player dead, false if not dead
    virtual bool DoDamage(float d);
	
	
};
