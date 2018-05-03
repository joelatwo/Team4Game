// Fill out your copyright notice in the Description page of Project Settings.

#include "../../inc/SHPawn.h"
#include "../../inc/SHHealth.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "../../inc/SHPawnMovementComponent.h"


ASHPawn::ASHPawn()
{
 	// Set this pawn to call Tick() every frame.
	PrimaryActorTick.bCanEverTick = true;
    
    // Set this pawn to be controlled by the lowest-numbered player
    AutoPossessPlayer = EAutoReceiveInput::Player0;
    
    // The root component will be a sphere that reacts to physics
    USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
    SetRootComponent(SphereComponent);
    SphereComponent->InitSphereRadius(40.0f);
    SphereComponent->SetCollisionProfileName(TEXT("Pawn"));
    //The sphere should generate hit events
    SphereComponent->SetNotifyRigidBodyCollision(true);
    //Add the OnHit function as a delegate to the hit event
    SphereComponent->OnComponentHit.AddDynamic(this, &ASHPawn::OnHit);
    
    
    // Create and position a mesh component so we can see where our sphere is
    UStaticMeshComponent* Visual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
    Visual->SetupAttachment(RootComponent);
    static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO'"));
    UStaticMesh* Asset = MeshAsset.Object;
    Visual->SetStaticMesh(Asset);
    
    // Use a spring arm to give the camera smooth, natural-feeling motion
    USpringArmComponent* SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraAttachmentArm"));
    SpringArm->SetupAttachment(RootComponent);
    // Position arm and set some default setting
    //The following two lines keep the camera from rotating with the player
    //Since the player spins a lot, that would probably make players vomit
    SpringArm->bUsePawnControlRotation = false;
    SpringArm->bAbsoluteRotation = true;
    SpringArm->bDoCollisionTest = false;
    SpringArm->RelativeRotation = FRotator(-90.f, 0.f, 0.f);
    SpringArm->TargetArmLength = 1200.0f;
    SpringArm->bEnableCameraLag = true;
    SpringArm->CameraLagSpeed = 3.0f;
    
    
    // Create a camera and attach to the spring arm
    UCameraComponent* Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("ActualCamera"));
    //Absolute rotation keeps it from rotating with the player
    Camera->bAbsoluteRotation = true;
    Camera->RelativeRotation = FRotator(-90.f, 0.f, 0.f);
    Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
    
    //Create the Weapon Manager and position it on the visual
    WeaponManager = CreateDefaultSubobject<UAOWeaponManager>(TEXT("WeaponManager"));
    WeaponManager->SetupAttachment(Visual);
    WeaponManager->RelativeLocation = FVector(25.f, 0, 0);
    
    // Create an instance of the movement component, and tell it to update the root component.
    MovementComponent = CreateDefaultSubobject<USHPawnMovementComponent>(TEXT("PawnMovementComponent"));
    MovementComponent->UpdatedComponent = RootComponent;
    
    //Set up the player state object and give the player some health
    PlayerState = new SHHealth(1000);
    
    // Inititalize the hit information. The player is invincible for one second after getting hit.
    HitCounter = 0;
    HitCooldown = 1;
    
}

void ASHPawn::Description()
{
    UE_LOG(LogTemp, Warning, TEXT("A pawn!"));
}

void ASHPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    //Count how long it has been sinc the player has been hit
    HitCounter += DeltaTime;
}

void ASHPawn::Move_YAxis(float AxisValue)
{
    //If has valid movement compoenent, move up/down
    if (MovementComponent && (MovementComponent->UpdatedComponent == RootComponent))
    {
        //The axes are backward for some reason, so use x axis vector to move along y axis
        MovementComponent->AddInputVector(FVector(1,0,0) * AxisValue);
    }
}

void ASHPawn::Move_XAxis(float AxisValue)
{
    //If has valid movement compoenent, move up/down
    if (MovementComponent && (MovementComponent->UpdatedComponent == RootComponent))
    {
        //The axes are backward for some reason, so use y axis vector to move along x axis
        MovementComponent->AddInputVector(FVector(0,1,0) * AxisValue);
    }
}

void ASHPawn::Shoot()
{
    //Ask weapon manager to shoot
    if (WeaponManager != NULL)
        WeaponManager->Shoot();
}

void ASHPawn::LookDir(FVector Position)
{
    FVector Direction = Position - GetActorLocation();
    FRotator Rotation = Direction.Rotation();
    //Only rotate using yaw
    Rotation = FRotator(0,Rotation.Yaw,0);
    SetActorRotation(Rotation);
}

void ASHPawn::LookMouse(FVector Direction)
{
    FRotator Rotation = Direction.Rotation();
    //Only rotation using yaw
    Rotation = FRotator(0,Rotation.Yaw,0);
    SetActorRotation(Rotation);
}

void ASHPawn::OnHit(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    //If enough time has passed since the last time a hit occured and the hit was an enemy...
    if (HitCounter > HitCooldown && OtherActor->GetActorLabel().Contains(TEXT("DSEnemy")))
    {
        //Reset counter, take some damage
        HitCounter = 0;
        bool Dead = PlayerState->DoDamage(250);
        if (Dead)
        {
            //GameOver
        }
    }
}


