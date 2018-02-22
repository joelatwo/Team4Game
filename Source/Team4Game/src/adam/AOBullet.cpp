// Fill out your copyright notice in the Description page of Project Settings.

#include "AOBullet.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AAOBullet::AAOBullet()
{

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// make sphere for collision representation
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	// collision radius
	CollisionComponent->InitSphereRadius(15.0f);
	// set root component to be the collision component
	RootComponent = CollisionComponent;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("bullet mesh"));
	
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/StarterContent/Props/MaterialSphere.MaterialSphere'"));
	Mesh->SetStaticMesh(MeshAsset.Object);
	Mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AAOBullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAOBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

