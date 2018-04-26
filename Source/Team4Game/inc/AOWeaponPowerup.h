// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "AOWeapon.h"

class TEAM4GAME_API AOPowerup : public AOWeapon {
public:
	AOPowerup(float Damage, AOWeapon* Weapon);
	virtual float GetDamage() override;
private:
	class AOWeapon * Weapon;
};