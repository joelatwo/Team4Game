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
    
    UPROPERTY(EditAnywhere)
    UAOWeaponManager* WeaponManager1;
protected:
    // Called when the game starts or when spawned;
    //virtual void BeginPlay() override;
public:
	ASHPawnTwoGuns();
	~ASHPawnTwoGuns();
    virtual void Shoot() override;
};
