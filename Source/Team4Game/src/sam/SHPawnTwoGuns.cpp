// Fill out your copyright notice in the Description page of Project Settings.

#include "../../inc/SHPawnTwoGuns.h"

ASHPawnTwoGuns::ASHPawnTwoGuns()
{
    
    WeaponManager1 = CreateDefaultSubobject<UAOWeaponManager>(TEXT("WeaponManager1"));
    WeaponManager1->SetupAttachment(RootComponent);
}

ASHPawnTwoGuns::~ASHPawnTwoGuns()
{
}


void ASHPawnTwoGuns::Shoot()
{
    ASHPawn::Shoot();
    if (WeaponManager1 != NULL)
        WeaponManager1->Shoot();
}
