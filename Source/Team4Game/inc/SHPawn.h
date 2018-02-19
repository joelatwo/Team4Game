// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SHPawn.generated.h"

UCLASS()
class TEAM4GAME_API ASHPawn : public APawn
{
	GENERATED_BODY()
    
    //This allows the mesh to be set within Unreal
    UPROPERTY(EditDefaultsOnly)
    UStaticMeshComponent* mSphereVisual;
public:
	// Sets default values for this pawn's properties
	ASHPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    //Input functions
    void Move_XAxis(float AxisValue);
    void Move_YAxis(float AxisValue);

private:
    //Input variables
    FVector CurrentVelocity;
	
};
