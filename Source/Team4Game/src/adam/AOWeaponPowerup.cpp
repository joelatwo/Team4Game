#include "../../inc/AOWeaponPowerup.h"

AOPowerup::AOPowerup(float Damage, AOWeapon* Weapon) {
	this->Damage = Damage;
	this->Weapon = Weapon;
}

float AOPowerup::GetDamage() {
	return Weapon->GetDamage() + self->Damage;
}
