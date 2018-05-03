// Fill out your copyright notice in the Description page of Project Settings.

#include "../../inc/SHPlayerState.h"

SHPlayerState::SHPlayerState()
{
}

SHPlayerState::~SHPlayerState()
{
}


float SHPlayerState::GetHealth()
{
    return Health;
}

bool SHPlayerState::SetHealth(float h)
{
    Health = h;
    return true;
}

bool SHPlayerState::DoDamage(float d)
{
    Health -= d;
    UE_LOG(LogTemp, Warning, TEXT("health: %f"), Health);
    if (Health < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
