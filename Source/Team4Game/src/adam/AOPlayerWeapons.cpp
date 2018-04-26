#include "../../inc/AOPlayerWeapons.h"
#include "../../inc/AOWeapon.h"

AOPlayerWeapons* AOPlayerWeapons::UniqueInstance = 0;

AOPlayerWeapons* AOPlayerWeapons::GetInstance() {
	if (UniqueInstance == nullptr)
		UniqueInstance = new AOPlayerWeapons();
	return UniqueInstance;
}

AOPlayerWeapons::AOPlayerWeapons() {
	CurrentWeapon = 0; // make current weapon weapon #1 in inventory
}

void AOPlayerWeapons::ChangeWeapon(int WeaponIndex) {
	if (WeaponIndex < 0 || WeaponIndex > 2) {
		return;
	}
	else if (WeaponList[WeaponIndex] == nullptr) {
		return;
	}
	else {
		CurrentWeapon = WeaponIndex;
	}
}

float AOPlayerWeapons::HeldWeaponDamage() {
	return WeaponList[CurrentWeapon]->GetDamage();
}