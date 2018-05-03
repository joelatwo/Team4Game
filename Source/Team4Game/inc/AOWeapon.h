// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"


class TEAM4GAME_API AOWeapon {
public:
    AOWeapon();
	AOWeapon(float Damage);
	virtual float GetDamage();
private:
	float Damage;
};
