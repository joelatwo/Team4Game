// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MAMap.h"
#include "SHSpawner.generated.h"

/* In an ideal world, there would be some manager class that spawns and places everything.
 * Enemies, player, maps, etc. That has yet to happen, however. So in the meantime,
 * to get some objects in the level, this class exists.
 * It is a singleton because it is responsible for spawning objects.
 * Being a singleton protects from spawning multiple environments. That would completely break the game.
 * This class also spawns the player pawn and sets test/stress modes for the player.
 * It does all of this at the beginning of the game.
 */
UCLASS()
class TEAM4GAME_API ASHSpawner : public AActor
{
    GENERATED_BODY()
    //Singleton instance
    static ASHSpawner* Instance;
    
    //Whether test mode is enabled
    //Can be set in editor
    UPROPERTY(EditAnywhere)
    bool bTest = false;
    
    //Whether stress mode is enabled
    //Can be set in editor
    UPROPERTY(EditAnywhere)
    bool bStress = false;
    
    //Whether default pawn or two gun pawn should be spawned
    //Can be set in editor
    UPROPERTY(EditAnywhere)
    bool bSpawnDefaultPawn = true;
public:
    /**
     * Is stress mode activated?
     * @return stress mode activated
     */
    bool GetStress();
    /**
     * Is test mode activated?
     * @return test mode activated
     */
    bool GetTest();
    /**
     * Set whether test mode is activated.
     * @param StressValue - the value that bStress should be set to
     */
    void SetStress(bool StressValue);
    /**
     * Sets whether stress mode is activated
     * @param TestValue - the value that bTest should be set to
     */
    void SetTest(bool TestValue);
    /**
     * Spawns the pawn; meant to be used to spawn it once the level starts.
     */
    void SpawnPawn();
    /**
     * Destroys old map and spawns new map.
     */
    void NewMap();
    /**
     * Access the singleton isntance of this class
     * @return the singleton instance of ASHSpawner
     */
    ASHSpawner* GetInstance();
    
protected:
    // Called when the game starts; setup singleton
    virtual void BeginPlay() override;
    
private:
    class AMAMap* Map;
    void SpawnDefaultPawn();
    void SpawnTwoGunPawn();
    
};
