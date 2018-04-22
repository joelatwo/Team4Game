// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SHPawn.h"
#include "SHPawnTwoGuns.generated.h"

/**
 * 
 */
UCLASS()
class TEAM4GAME_API ASHPawnTwoGuns : public ASHPawn
{
    GENERATED_BODY()
    
    
protected:
    UAOWeaponManager* WeaponManager1;
public:
	ASHPawnTwoGuns();
	~ASHPawnTwoGuns();
    virtual void Shoot() override;
};
