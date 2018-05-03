// Fill out your copyright notice in the Description page of Project Settings.

#include "../../inc/SHPawnTwoGuns.h"
#include "../../inc/SHArmor.h"

ASHPawnTwoGuns::ASHPawnTwoGuns()
{
    //Create a second gun
    WeaponManager1 = CreateDefaultSubobject<UAOWeaponManager>(TEXT("WeaponManager1"));
    WeaponManager1->SetupAttachment(RootComponent);
    
    //Position both guns
    WeaponManager->RelativeLocation = FVector(25.f, 50.f, 0);
    WeaponManager1->RelativeLocation = FVector(25.f, -50.f, 0);
    
    //Add some armor by decorating PlayerState
    //PlayerState = new SHArmor(50.0, PlayerState);
}

void ASHPawnTwoGuns::Description()
{
    UE_LOG(LogTemp, Warning, TEXT("A pawn with two guns!"));
}

void ASHPawnTwoGuns::Shoot()
{
    //Shoot the first gun
    ASHPawn::Shoot();
    //Shoot the second gun
    if (WeaponManager1 != NULL)
        WeaponManager1->Shoot();
}
