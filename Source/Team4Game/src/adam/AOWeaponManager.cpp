// Fill out your copyright notice in the Description page of Project Settings.

#include "../../inc/AOWeaponManager.h"
#include "AOBullet.h"
#include "Engine/World.h"
#include "UObject/Class.h"
#include "../Source/Team4Game/inc/AOPlayerWeapons.h"


// Sets default values for this component's properties
UAOWeaponManager::UAOWeaponManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Shoot a bullet
// TODO: make bullet spawn slightly in front of player so it doesn't move player
void UAOWeaponManager::Shoot()
{
	// spawn AAOBullet object at gun pointing same direction as gun
	FTransform GunTransform = GetComponentTransform();	
	FActorSpawnParameters SpawnParams;	
	AAOBullet* Projectile = GetWorld()->SpawnActor<AAOBullet>(GunTransform.GetTranslation(), GunTransform.Rotator(), SpawnParams);
}

// Called when the game starts
void UAOWeaponManager::BeginPlay()
{
	Super::BeginPlay();	
}


// Called every frame
void UAOWeaponManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
