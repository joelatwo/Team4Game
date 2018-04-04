// Fill out your copyright notice in the Description page of Project Settings.

#include "../../inc/SHPawn.h"
#include "../../inc/MAMap.h"
#include "../../inc/SHPawnMovementComponent.h"

// ...
// Sets default values
ASHPawn::ASHPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    // Set this pawn to be controlled by the lowest-numbered player
    AutoPossessPlayer = EAutoReceiveInput::Player0;
    
    // Our root component will be a sphere that reacts to physics
    SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
    SetRootComponent(SphereComponent);
    SphereComponent->InitSphereRadius(40.0f);
    SphereComponent->SetCollisionProfileName(TEXT("Pawn"));
    
    
    // Create and position a mesh component so we can see where our sphere is
    mSphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
    mSphereVisual->SetupAttachment(RootComponent);
    
    // Create and position a mesh component so we can see where our gun is
    //mGunVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GunRepresentation"));
    //mGunVisual->SetupAttachment(mSphereVisual);
    
    // Use a spring arm to give the camera smooth, natural-feeling motion.
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraAttachmentArm"));
    SpringArm->SetupAttachment(RootComponent);
    SpringArm->RelativeRotation = FRotator(-90.f, 0.f, 0.f);
    SpringArm->TargetArmLength = 1200.0f;
    SpringArm->bEnableCameraLag = true;
    SpringArm->CameraLagSpeed = 3.0f;
    SpringArm->bUsePawnControlRotation = false;
    SpringArm->bAbsoluteRotation = true;
    
    // Create a camera and attach to our spring arm
    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("ActualCamera"));
    Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
    Camera->bAbsoluteRotation = true;
    
    WeaponManager = CreateDefaultSubobject<UAOWeaponManager>(TEXT("WeaponManager"));
    WeaponManager->SetupAttachment(mSphereVisual);
    
    // Create an instance of our movement component, and tell it to update our root component.
    MovementComponent = CreateDefaultSubobject<USHPawnMovementComponent>(TEXT("PawnMovementComponent"));
    MovementComponent->UpdatedComponent = RootComponent;
    
}

// Called when the game starts or when spawned
void ASHPawn::BeginPlay()
{
	Super::BeginPlay();
    AMAMap *LevelMap = GetWorld()->SpawnActor<AMAMap>(FVector(-1250,-1250,100),FRotator(0,0,0),FActorSpawnParameters());
}

// Called every frame
void ASHPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    if (!CurrentVelocity.IsZero())
    {
        FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
        SetActorLocation(NewLocation);
    }
}

bool ASHPawn::GetTest()
{
    return mTest;
}

void ASHPawn::SetTest(bool b)
{
    mTest = b;
}

bool ASHPawn::GetStress()
{
    return mStress;
}

void ASHPawn::SetStress(bool b)
{
    mStress = b;
}

//For some reason the axes are mixed up, so use x component of vector instead of y
void ASHPawn::Move_YAxis(float AxisValue)
{
    if (MovementComponent && (MovementComponent->UpdatedComponent == RootComponent))
    {
        MovementComponent->AddInputVector(FVector(1,0,0) * AxisValue);
    }
}

//For some reason the axes are mixed up, so use y component of vector instead of x
void ASHPawn::Move_XAxis(float AxisValue)
{
    if (MovementComponent && (MovementComponent->UpdatedComponent == RootComponent))
    {
        MovementComponent->AddInputVector(FVector(0,1,0) * AxisValue);
    }
}

//Ask the weapon manager ot shoot
void ASHPawn::Shoot()
{
    if (WeaponManager != NULL)
        WeaponManager->Shoot();
}

void ASHPawn::LookDir(FVector pos)
{
    FVector dir = pos - GetActorLocation();
    FRotator r = dir.Rotation();
    r = FRotator(0,r.Yaw,0);
    //UE_LOG(LogTemp, Warning, TEXT("r: %s"), *dir.ToString());
    SetActorRotation(r);
}

void ASHPawn::LookMouse(FVector pos)
{
    FRotator r = pos.Rotation();
    r = FRotator(0,r.Yaw,0);
    //UE_LOG(LogTemp, Warning, TEXT("r: %s"), *dir.ToString());
    SetActorRotation(r);
}

