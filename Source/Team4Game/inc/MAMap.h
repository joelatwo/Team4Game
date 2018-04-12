// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "ConstructorHelpers.h"
#include "Engine.h"
#include "Engine/World.h"
#include <random>
#include <ctime>
#include "MAMap.generated.h"


//number of cells in X and Y
#define floorWidth 32
#define floorHeight 32
//the mesh I'm using currently (cube) has dimensions of 100 on each side;
//this could be changed in the future
#define cellWidth 100
#define cellHeight 100

UCLASS()
class TEAM4GAME_API AMAMap : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	int tileHeight;
	int tileWidth;
	AMAMap();
	void update(int Grid[][floorHeight]);
	int getNeighbors(int x, int y, int Grid[][floorHeight]);


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
		class UInstancedStaticMeshComponent *floorMeshComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
		class UInstancedStaticMeshComponent *wallMeshComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Material")
		class UMaterial* floorMaterial;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void mapGen();
	FVector position, scale, rotate;
	FQuat rotateQ;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	
};
