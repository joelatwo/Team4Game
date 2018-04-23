// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "DSEnemy.generated.h"

UCLASS()
class TEAM4GAME_API ADSEnemy : public APawn
{
	GENERATED_BODY()
	//allows for a mesh to be created for our enemies
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* visual;
	UFUNCTION(BlueprintCallable, Category = "HighScore")
		static void SendHighScore();
	UFUNCTION(BlueprintCallable, Category = "HighScore")
		static void AddToScore();
public:
	// Sets default values for this pawn's properties
	ADSEnemy(const class FObjectInitializer &Initializer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private: 
	int GetScore();
	void SetScore(int newscore);
	int CurrScore = 0;
	
};
