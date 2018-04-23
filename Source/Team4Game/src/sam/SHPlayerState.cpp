// Fill out your copyright notice in the Description page of Project Settings.

#include "../../inc/SHPlayerState.h"

float SHPlayerState::GetHealth()
{
    return Health;
}

void SHPlayerState::SetHealth(float HealthValue)
{
    Health = HealthValue;
}

bool SHPlayerState::DoDamage(float Damage)
{
    Health -= Damage;
    if (Health < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
