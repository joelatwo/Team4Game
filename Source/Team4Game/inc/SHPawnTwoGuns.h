// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SHPawn.h"
#include "SHPawnTwoGuns.generated.h"

/**
 * Adds a second gun to the palyer
 */
UCLASS()
class TEAM4GAME_API ASHPawnTwoGuns : public ASHPawn
{
    GENERATED_BODY()
    
    
protected:
    //A second weapon manager that works as the second gun
    UAOWeaponManager* WeaponManager1;
public:
    //Create the second weapon manager and position both weapon managers
	ASHPawnTwoGuns();
    //Shoot both weapons
    virtual void Shoot() override;
};
