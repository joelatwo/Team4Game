// Fill out your copyright notice in the Description page of Project Settings.

#include "../../inc/SHHealth.h"

SHHealth::SHHealth(float HealthValue)
{
    this->Life = HealthValue;
}

void SHHealth::Heal(float HealAmount)
{
    Life += HealAmount;
}

bool SHHealth::DoDamage(float Damage)
{
    Life -= Damage;
    if (Life < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
