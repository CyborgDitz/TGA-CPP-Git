#include "EnemyType.h"

#include <iostream>

EnemyType::EnemyType() { }

EnemyType::EnemyType(const char* aName, const int aMaxHealth, const int aMyAtk, const bool aHasLoot)
{
    strcpy_s(myName, aName);
    myMaxHealth = aMaxHealth;
    myHealth = myMaxHealth;
    myAtk = aMyAtk;
    myHasLoot = aHasLoot;
    SetCurrentHealthToMax();
}
