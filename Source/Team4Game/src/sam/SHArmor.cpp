// Fill out your copyright notice in the Description page of Project Settings.

#include "../../inc/SHArmor.h"

SHArmor::SHArmor(float armorValue, SHPlayerState* playerState)
{
    this->armor = armorValue;
    this->playerState = playerState;
    
}

SHArmor::~SHArmor()
{
}

bool SHArmor::DoDamage(float d)
{
    d -= this->armor;
    return playerState->DoDamage(d);
}
