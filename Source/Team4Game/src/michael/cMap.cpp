// Fill out your copyright notice in the Description page of Project Settings.

#include "cMap.h"

/*** TODO ***
* make the base floor a single instance of a single mesh? instead of a consistent array,
* then add instanced meshes on top of that.
*
* - find meshes to use that look good, rather than cubes
* -
*
*/

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White,text)

// Sets default values
AcMap::AcMap()
{

	mapGen();
}


//too much is going on in this function,
//I'll be splitting this up into multiple...or at least simplifying it
void AcMap::mapGen() {

	std::mt19937 generator(time(0));
	std::uniform_real_distribution<float> dis(0.0, 1.0);
	//mesh:  100^3 cube
	static ConstructorHelpers::FObjectFinder<class UStaticMesh> floorMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));

	floorMeshComponent = NewObject<UInstancedStaticMeshComponent>(this, TEXT("BLOCK"));
	floorMeshComponent->SetStaticMesh(floorMesh.Object);

	RootComponent = floorMeshComponent;
	//floorMeshComponent->AddInstance(FTransform(rotateQ, position, floorScale));

	int Grid[floorWidth][floorHeight];

	for (int i = 0; i < floorWidth; i++) {
		for (int j = 0; j < floorHeight; j++) {
			if (i == 0 || j == 0 || i == floorWidth - 1 || j == floorHeight - 1)
				Grid[i][j] = 1;

			else if (dis(generator) > 0.6)
				Grid[i][j] = 1;
			else
				Grid[i][j] = 0;
		}
	}
	//run gen 6 x
	for (int i = 0; i < 6; i++)
		update(Grid);

	for (int i = 0; i < floorWidth; i++) {
		for (int j = 0; j < floorHeight; j++) {
			position.X = i * cellWidth;
			position.Y = j * cellHeight;
			position.Z = 0;
			floorMeshComponent->AddInstance(FTransform(position));
			if (Grid[i][j] == 1) {
				//raise position up 1 cube height, and place mesh
				position.Z = 100;
				floorMeshComponent->AddInstance(FTransform(position));
				position.Z = 0;

			}

		}
	}
}
void AcMap::update(int Grid[][floorHeight]) {
	int turnOn = 4;
	int turnOff = 4;
	int newGrid[floorWidth][floorHeight];
	for (int i = 0; i < floorWidth; i++) {
		for (int j = 0; j < floorHeight; j++) {
			newGrid[i][j] = Grid[i][j];
		}
	}
	//if a 1 is touching fewer than four 1s, turn it to 0, and vice versa
	for (int i = 1; i < floorWidth - 1; i++) {
		for (int j = 1; j < floorHeight - 1; j++) {
			int on = newGrid[i][j];
			int count = getNeighbors(i, j, newGrid);
			if (on && count < turnOff)	Grid[i][j] = 0;
			if (!on && count > turnOn)	Grid[i][j] = 1;
		}
	}
}

//count num of Neighboring cells with value 1
int AcMap::getNeighbors(int x, int y, int Grid[][floorHeight]) {
	int count = 0;
	if (x < floorWidth - 1) {
		count += Grid[x + 1][y];
		if (y < floorHeight - 1)
			count += Grid[x + 1][y + 1];
		if (y > 0)
			count += Grid[x + 1][y - 1];
	}
	if (x > 0) {
		count += Grid[x - 1][y];
		if (y < floorHeight - 1)
			count += Grid[x - 1][y + 1];
		if (y > 0)
			count += Grid[x - 1][y - 1];
	}

	if (y < floorHeight - 1)
		count += Grid[x][y + 1];
	if (y > 0)
		count += Grid[x][y - 1];

	return count;
}
// Called when the game starts or when spawned
void AcMap::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AcMap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

