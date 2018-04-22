// Fill out your copyright notice in the Description page of Project Settings.

#include "AOBullet.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AAOBullet::AAOBullet()
{
	// bullet disappears after 3 seconds
	InitialLifeSpan = 3.0f;

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// make sphere for collision representation
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	// collision radius
	CollisionComponent->InitSphereRadius(1.0f);
	// set root component to be the collision component
	RootComponent = CollisionComponent;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("bullet mesh"));
	
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/StarterContent/Props/MaterialSphere.MaterialSphere'"));
	Mesh->SetStaticMesh(MeshAsset.Object);
	Mesh->SetupAttachment(RootComponent);

	// Use this component to drive this projectile's movement.
	float speed = 3000.0f;// make bullet pretty fast
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);
	ProjectileMovementComponent->InitialSpeed = speed;
	ProjectileMovementComponent->MaxSpeed = speed;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->bShouldBounce = true;
	ProjectileMovementComponent->Bounciness = 0.3f;

	// fire in direction
	FireInDirection(this->GetActorForwardVector());
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

// set bullet to move in given direction
void AAOBullet::FireInDirection(const FVector& ShootDirection)
{
	// initialize the projectile's velocity in the shoot direction.
	ProjectileMovementComponent->Velocity = ShootDirection * ProjectileMovementComponent->InitialSpeed;
}
