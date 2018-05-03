// Fill out your copyright notice in the Description page of Project Settings.

#include "../../inc/SHPawn.h"
#include "../../inc/SHArmor.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
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
    USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
    SetRootComponent(SphereComponent);
    SphereComponent->InitSphereRadius(40.0f);
    SphereComponent->SetCollisionProfileName(TEXT("Pawn"));
    SphereComponent->SetNotifyRigidBodyCollision(true);
    SphereComponent->OnComponentHit.AddDynamic(this, &ASHPawn::OnHit);
    
    
    // Create and position a mesh component so we can see where our sphere is
    UStaticMeshComponent* mSphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
    mSphereVisual->SetupAttachment(RootComponent);
    static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO'"));
    UStaticMesh* Asset = MeshAsset.Object;
    mSphereVisual->SetStaticMesh(Asset);
    
    // Create and position a mesh component so we can see where our gun is
    //mGunVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GunRepresentation"));
    //mGunVisual->SetupAttachment(mSphereVisual);
    
    // Use a spring arm to give the camera smooth, natural-feeling motion.
    USpringArmComponent* SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraAttachmentArm"));
    SpringArm->SetupAttachment(RootComponent);
    SpringArm->bUsePawnControlRotation = false;
    SpringArm->bDoCollisionTest = false;
    SpringArm->bAbsoluteRotation = true;
    SpringArm->RelativeRotation = FRotator(-90.f, 0.f, 0.f);
    SpringArm->TargetArmLength = 1200.0f;
    SpringArm->bEnableCameraLag = true;
    SpringArm->CameraLagSpeed = 3.0f;
    
    
    // Create a camera and attach to our spring arm
    UCameraComponent* Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("ActualCamera"));
    Camera->bAbsoluteRotation = true;
    Camera->RelativeRotation = FRotator(-90.f, 0.f, 0.f);
    Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
    
    WeaponManager = CreateDefaultSubobject<UAOWeaponManager>(TEXT("WeaponManager"));
    WeaponManager->SetupAttachment(mSphereVisual);
    WeaponManager->RelativeLocation = FVector(25.f, 0, 0);
    
    // Create an instance of our movement component, and tell it to update our root component.
    MovementComponent = CreateDefaultSubobject<USHPawnMovementComponent>(TEXT("PawnMovementComponent"));
    MovementComponent->UpdatedComponent = RootComponent;
    
    PlayerState = new SHPlayerState;
    PlayerState->SetHealth(1000);
    PlayerState = new SHArmor(50.0, PlayerState);
    
    hitCounter = 0;
    hitCooldown = 1;
    
}

// Called when the game starts or when spawned
void ASHPawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASHPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    hitCounter += DeltaTime;
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

void ASHPawn::OnHit(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    if (hitCounter > hitCooldown && OtherActor->GetActorLabel().Contains(TEXT("DSEnemy")))
    {
        hitCounter = 0;
        bool dead = PlayerState->DoDamage(250);
        if (dead)
        {
            //GameOver
        }
    }
}


