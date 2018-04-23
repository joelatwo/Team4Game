// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class TEAM4GAME_API SHPlayerState
{
	
private:
    //How much health the player has
    float Health;
public:
    /**
     * Get the player's health
     * @return The player's current health value
     */
    float GetHealth();
    /**
     * Set how much health the player should ahve
     * @param HealthValue - how much health the player should have
     */
    void SetHealth(float HealthValue);
    /**
     * Decrease the player's health. Can be overridden by a decorator
     * @param Damage - the amount to decrease the player's health by
     * @return Whether the player is dead (health is less than zero)
     */
    virtual bool DoDamage(float Damage);
	
	
};
