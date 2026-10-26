#pragma once
#include <vector>

#include "Enemy.h"

#include "Player.h"
#include "Spell.h"


class Room
{
public:
    Room(const char* aName, int aDoorsAmount, int aEnemies, bool aHasCest, bool aHasItem, const Item& aItem, const Spell& aSpell);
    
    const char* GetName() const { return myName; }
    int GetDoorAmount() const { return myDoorsAmount; }
    int GetEnemiesAmount() const { return myEnemies; }

    void PrintRoomData(const std::vector<Enemy>* aPopulation) const;
    void PrintEnterRoom(const Player& aPlayer) const;
    void SetDoors(const int aDoors) { myDoorsAmount = aDoors; }
    bool GetHasChest() const { return myHasChest; }
    bool GetHasItems() const { return myHasItems; }
    bool GetHasSpell() const { return myHasSpell; }
    void SetHasSpell(const bool aActive) { myHasSpell = aActive; }
    void SetHasChest(const bool aHasChest) { myHasChest = aHasChest; }
    void SetHasItems(const bool aHasItems) { myHasItems = aHasItems; }
    void SetEnemiesAmount(const int aEnemies) { myEnemies = aEnemies; }
    
    Item& GetItem() { return myItem; }
    Spell& GetSpell() { return mySpell; }

private:
    Item myItem;
    Spell mySpell;
    int myDoorsAmount = 2;
    int myEnemies{};
    const char* myName = "Room";
    bool myHasChest = false;
    bool myHasItems = false;
    bool myHasSpell = false;
    bool myHasEnemies = false;
};
