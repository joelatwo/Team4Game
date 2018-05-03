// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SHPlayerState.h"

/**
 *
 */
class TEAM4GAME_API SHArmor : public SHPlayerState
{
public:
    SHArmor(float armorValue, SHPlayerState* playerState);
    ~SHArmor();
    bool DoDamage(float d) override;
    
    
private:
    float armor;
    class SHPlayerState* playerState;
};
