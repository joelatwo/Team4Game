// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SHPlayerState.h"

/**
 * Player life is health that can be healed.
 */
class TEAM4GAME_API SHHealth : public SHPlayerState
{
public:
    /**
     * Create a SHHealth instance with a certain amount of health.
     * @param HealthValue - the amount of health the player should have
     */
	SHHealth(float HealthValue);
    /**
     * Decrease the player's health.
     * @param Damage - the amount to decrease the player's health by
     * @return Whether the player is dead (health is less than zero)
     */
    virtual bool DoDamage(float Damage) override;
    /**
     * Increase the player's health
     * @param HealAmount - the amount to increase the player's health by
     */
    void Heal(float HealAmount);
};
