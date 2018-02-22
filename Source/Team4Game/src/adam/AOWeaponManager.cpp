// Fill out your copyright notice in the Description page of Project Settings.

#include "../../inc/AOWeaponManager.h"
#include "AOBullet.h"
#include "Engine/World.h"
#include "UObject/Class.h"
//#include "Runtime/Engine/Classes/GameFramework/Actor.h"


// Sets default values for this component's properties
UAOWeaponManager::UAOWeaponManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Shoot a bullet
void UAOWeaponManager::Shoot()
{
	/*	
	// Get the camera transform.
	FVector CameraLocation;
	FRotator CameraRotation;
	GetActorEyesViewPoint(CameraLocation, CameraRotation);
	*/

	FTransform GunTransform = GetComponentTransform();

	UWorld* World = GetWorld();
	
	FActorSpawnParameters SpawnParams;
	//SpawnParams.Owner = (AActor * ) this;
	
	AAOBullet* Projectile = GetWorld()->SpawnActor<AAOBullet>(GunTransform.GetTranslation(), GunTransform.Rotator(), SpawnParams);

}

// Called when the game starts
void UAOWeaponManager::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAOWeaponManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

