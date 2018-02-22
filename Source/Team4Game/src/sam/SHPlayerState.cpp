// Fill out your copyright notice in the Description page of Project Settings.

#include "../../inc/SHPlayerState.h"

/*SHPlayerState::SHPlayerState()
{
}

SHPlayerState::~SHPlayerState()
{
}*/


float ASHPlayerState::getHealth()
{
    return health;
}

bool ASHPlayerState::setHealth(float h)
{
    health = h;
    return true;
}
