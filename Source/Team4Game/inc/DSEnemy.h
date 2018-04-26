// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include <string.h>
#include "DSEnemy.generated.h"

UCLASS()
class TEAM4GAME_API ADSEnemy : public APawn
{
	GENERATED_BODY()
	//allows for a mesh to be created for our enemies
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* visual;
	//Sends high score to high score server.
	//Needs to have a name and the score to send. 
	UFUNCTION(BlueprintCallable, Category = "HighScore") 
		static void SendHighScore(int score, FString name);
	//Change enemy count on the field 
	//Return the enemy count after modification
	UFUNCTION(BlueprintCallable, Category = "HighScore")
		static int ChangeEnemyAmount(int amountToChange);
	//Add the ScoreToAdd to the total score
	//Return the total score after modification
	UFUNCTION(BlueprintCallable, Category = "HighScore") 
		static int AddToScore(int scoreToAdd);
public:
	// Sets default values for this pawn's properties
	// Used generically by Unreal.
	ADSEnemy(const class FObjectInitializer &Initializer);

protected:
	// Called when the game starts or when spawned
	// Used generically by Unreal.
	virtual void BeginPlay() override;

public:	
	// Called every frame
	// Used generically by Unreal.
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	// Used generically by Unreal.
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
};
