// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SHSpawner.generated.h"

/* This class in a singleton because it is responsible for spawning objects.
 * Being a singleton protects from spawning multiple environments.
 */
UCLASS()
class TEAM4GAME_API ASHSpawner : public AActor
{
    GENERATED_BODY()
    static ASHSpawner* instance;
    
    UPROPERTY(EditAnywhere)
    bool mTest = false;
    
    UPROPERTY(EditAnywhere)
    bool mStress = false;
    
    UPROPERTY(EditAnywhere)
    bool bSpawnDefaultPawn = true;
public:
    // Sets default values for this component's properties
    ASHSpawner();
    bool GetStress(bool b);
    bool GetTest(bool b);
    void SetStress(bool b);
    void SetTest(bool b);
    ASHSpawner* GetInstance();
    
protected:
    // Called when the game starts
    virtual void BeginPlay() override;
    
    
private:
    void SpawnDefaultPawn();
    void SpawnTwoGunPawn();
    
};
