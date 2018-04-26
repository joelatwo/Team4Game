// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "AOWeapon.h"
#include "CoreMinimal.h"


/* 
* Adapted from  github gist:1098199 (https://gist.github.com/pazdera/1098119)
* The above code is licensed under GNU General Public License.
*/

class TEAM4GAME_API AOPlayerWeapons {
private:
	static AOPlayerWeapons* UniqueInstance;
	AOPlayerWeapons();

	AOWeapon * WeaponList[3] = { new AOWeapon(5.0), 0, 0 };
	int CurrentWeapon;
public:
	static AOPlayerWeapons* GetInstance();
	void ChangeWeapon(int WeaponIndex);
	float HeldWeaponDamage();
};