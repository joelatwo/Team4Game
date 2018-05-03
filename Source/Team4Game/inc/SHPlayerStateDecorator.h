// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SHPlayerState.h"

/**
 * 
 */
class TEAM4GAME_API SHPlayerStateDecorator : public SHPlayerState
{
public:
	virtual bool DoDamage(float Damage) = 0;
};
