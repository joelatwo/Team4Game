#include "../../inc/AOWeapon.h"

AOWeapon::AOWeapon(float Damage) {
	this->Damage = Damage;
}

float AOWeapon::GetDamage() {
	return this->Damage;
}