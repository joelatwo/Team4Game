// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SHPlayerState.h"

/**
 * A decorator for SHPlayerState.
 * Using a decorator allows flexibility to add new stats to the player, like armor, resistance, etc.
 */
class TEAM4GAME_API SHArmor : public SHPlayerState
{
public:
    /**
     * Create an armor instance with a specific armor value and a parent SHPlayerState
     * @param ArmorValue - the amount of armor the player should have
     * @param State - the parent SHPlayerState object
     */
    SHArmor(float ArmorValue, SHPlayerState* State);
    /**
     * Subtract the armor value from the damage done; then call the base DoDamage()
     * @param Damage - the amount of damage to do
     * @return whether the pawn is out of health
     */
    bool DoDamage(float Damage) override;
    /**
     * Sets the value of Armor
     * @param ArmorValue - the amount of armor the player should have
     */
    void SetArmor(float ArmorValue);
    /**
     * Gets the value of armor.
     * @return The player's armor value
     */
    float GetArmor();
    
private:
    //A flat reduction to damage
    float Armor;
    //The parent SHPlayerState object. Could be an actual SHPlayerState or a different decorator.
    class SHPlayerState* PlayerState;
};
