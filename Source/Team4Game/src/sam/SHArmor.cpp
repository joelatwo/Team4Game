// Fill out your copyright notice in the Description page of Project Settings.

#include "../../inc/SHArmor.h"

SHArmor::SHArmor(float ArmorValue, SHPlayerState* State)
{
    this->Armor = ArmorValue;
    this->PlayerState = State;
    
}

void SHArmor::SetArmor(float ArmorValue)
{
    Armor = ArmorValue;
}

float SHArmor::GetArmor()
{
    return Armor;
}

bool SHArmor::DoDamage(float Damage)
{
    Damage -= this->Armor;
    return PlayerState->DoDamage(Damage);
}
