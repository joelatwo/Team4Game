// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SHPlayerController.generated.h"
/**
 * 
 */
UCLASS()
class TEAM4GAME_API ASHPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
    ASHPlayerController();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    
private:
    virtual void SetupInputComponent() override;

private:
    void MovePawnX(float AxisValue);
    void MovePawnY(float AxisValue);
	
};
