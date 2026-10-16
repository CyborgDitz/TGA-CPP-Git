#pragma once
#include <string.h>

class EnemyType
{
public:
    EnemyType();
    EnemyType(const char* aName, int aMaxHealth, int aMyAtk, bool aHasLoot);

    int GetHealth() const { return myHealth; }
    int GetMaxHealth() const { return myMaxHealth; }
    int GetAtk() const { return myAtk; }
    bool GetIsAlive() const { return myIsAlive; }
    int GetDefense() const { return myDefense; }
    bool GetHasLoot() const { return myHasLoot; }
    const char* GetName() const { return myName; }
    void SetIsAlive(bool aIsAlive) { myIsAlive = aIsAlive; }

    void SetMaxHealth(const int aMaxHealth) { myMaxHealth = aMaxHealth; }
    void SetCurrentHealthToMax() { myHealth = myMaxHealth; }
    void SetAtk(const int aAtk) { myAtk = aAtk; }
    void SetDefense(const int aDefense) { myDefense = aDefense; }
    void SetHasLoot(const bool aHasLoot) { myHasLoot = aHasLoot; }

    void SetName(const char* aName) { strcpy_s(myName, aName); }

private:
    char myName[17] = {};
    int myMaxHealth{};
    int myHealth{};
    int myAtk{};
    int myDefense{};
    bool myHasLoot = false;
    bool myIsAlive = true;
};
