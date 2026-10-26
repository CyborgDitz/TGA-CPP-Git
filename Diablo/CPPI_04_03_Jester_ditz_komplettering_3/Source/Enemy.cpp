#include "Enemy.h"

#include <algorithm>
#include <iostream>
#include <ostream>

Enemy::Enemy(const EnemyType& aEnemyType) : myEnemyType(&aEnemyType)
{
    myHealth = aEnemyType.GetHealth();
}

int Enemy::GetHealth() const
{
    return myEnemyType->GetHealth();
}

bool Enemy::GetHasLoot() const
{
    return myEnemyType->GetHasLoot();
}

int Enemy::GetMaxHealth() const
{
    return myEnemyType->GetMaxHealth();
}

int Enemy::GetAtk() const
{
    return myEnemyType->GetAtk();
}

int Enemy::GetDef() const
{
    return myEnemyType->GetDefense();
}

const char* Enemy::GetName() const
{
    return myEnemyType->GetName();
}


void Enemy::TakeDamage(const int aDamage)
{
    const char* myName = GetName();
    const int myCurrentHealth = myHealth;
    myHealth -= aDamage;
    myHealth = std::max(myHealth, 0);
    std::cout << myName << "has currently " << myCurrentHealth << " health\n" <<
        " and takes " << aDamage << ". Now has " << myHealth <<
        " health left!" << std::endl;
    if (myHealth <= 0)
    {
        myIsAlive = false;
        std::cout << myName << " is dead and removed from vector or something \n " << std::endl;
        return;
    }
    std::cout << "It is still standing!" << std::endl;
}

void Enemy::PrintStats() const
{
    std::cout << "The enemy: " << GetName() << " stats are : \n " <<
        "Current HP: " << myHealth << '\t' <<
        "MaxHP: " << GetMaxHealth() << '\n' <<
        "Atk: " << GetAtk() << '\t' <<
        "Def: " << GetDef() << '\n' << std::endl;
}
