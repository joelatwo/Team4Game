// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <string>

/**
 * 
 */
class TEAM4GAME_API JASoundSuperClass
{
public:
	JASoundSuperClass();
	~JASoundSuperClass();
protected:
	void PlaySoundEffect();
	int UpdateVolume(int NewVolume);
	string SoundFileName;
};
