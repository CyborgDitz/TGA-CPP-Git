#pragma once
#include <string>

#include "EnemyType.h"

enum class enumEnemyType
{
    Blob,
    BigBlob,
    Diablob,
    Count
};

class Enemy
{
public:
    Enemy(const EnemyType& aEnemyType);
    
    void SetHealth(const int aHealth) { myHealth = aHealth; }
    bool GetIsAlive() const { return myIsAlive; }
    void SetIsAlive(const bool aIsAlive) { myIsAlive = aIsAlive; }
    void SetHasLoot(const bool aHasLoot) { myHasLoot = aHasLoot; }
    bool GetHasLoot() const;
    int GetMaxHealth() const;
    int GetHealth() const;
    int GetAtk() const;
    int GetDef() const;
    const char* GetName() const;

    void TakeDamage(int aDamage);
    void PrintStats() const;

private:
    int myHealth{};
    bool myIsAlive = true;
    bool myHasLoot = false;
    const EnemyType* myEnemyType;
};
