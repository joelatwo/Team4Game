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
    //Sets up the handling of input
    virtual void SetupInputComponent() override;

private:
    //tells possessed pawn (player) to move left/right
    void MovePawnX(float AxisValue);
    //Tells player pawn to move forward/backward
    void MovePawnY(float AxisValue);
    //Tells player pawn to shoot
    void Shoot();
	
};
