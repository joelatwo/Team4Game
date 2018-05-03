// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * The abstract base class that contains the player's health and status information.
 * It uses the decorator pattern. The idea is to make a very flexible data structure
 * that allows for different implementations of "life"--health that can be healed,
 * something like durability that is finite, etc. These concrete life components can be
 * decorated with different resistances. Armor that gives a flat reduction to damage taken.
 * Percentage resistances to different enemy damage types (assuming that existed). Of course,
 * most of this has yet to be implemented. But with this structure, it could be.
 */
class TEAM4GAME_API SHPlayerState
{
	
protected:
    //The amount of life a player has left
    float Life;
public:
    /**
     * Get the player's life
     * @return The player's current life value
     */
    float GetLife();
    /**
     * Set how much life the player should have.
     * @param LifeValue - how much life the player should have
     */
    void SetLife(float LifeValue);
    /**
     * Decrease the player's life. Should be implemented by component/decorator
     * @param Damage - the amount to decrease the player's health by
     * @return Whether the player is dead (life is less than zero)
     */
    virtual bool DoDamage(float Damage) = 0;
	
	
};
