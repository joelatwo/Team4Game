// Fill out your copyright notice in the Description page of Project Settings.

#include "../../inc/SHPlayerState.h"

/*SHPlayerState::SHPlayerState()
{
}

SHPlayerState::~SHPlayerState()
{
}*/


float ASHPlayerState::GetHealth()
{
    return Health;
}

bool ASHPlayerState::SetHealth(float h)
{
    Health = h;
    return true;
}

bool ASHPlayerState::DoDamage(float d)
{
    Health -= d;
    if (Health < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
