#include "Room.h"
#include <iostream>


Room::Room(const char* aName, const int aDoorsAmount, const int aEnemies, const bool aHasCest, const bool aHasItem, const Item& aItem,
           const Spell& aSpell) : myItem(aItem), mySpell(aSpell)
{
    myName = aName;
    myDoorsAmount = aDoorsAmount;
    myEnemies = aEnemies;
    myHasChest = aHasCest;
    if (myEnemies > 0)
    {
        myHasEnemies = true;
    }
    myHasItems = aHasItem;
    myHasSpell = aSpell.GetHasSpellSlot();
}

void Room::PrintRoomData(const std::vector<Enemy>* aPopulation) const
{
    std::cout << "Room: " << myName << " has " << myDoorsAmount << " doors! " << std::endl;
    if (aPopulation->empty())
    {
        std::cout << "There are: " << aPopulation->size() << " enemies in here!" << std::endl;
    }
    else
    {
        std::cout << "No enemies present!" << std::endl;
    }
    if (myHasChest == true)
    {
        std::cout << "There is a chest!! " << std::endl;
    }
    if (myHasItems == true)
    {
        std::cout << "The loot is: " << myItem.GetName() << std::endl;
    }
    if (myHasSpell == true)
    {
        std::cout << "Your spellbook finds a powerful magic in the room! But you can only use it once!\n "
            "It is " << mySpell.GetName() << std::endl;
    }
    else
    {
        std::cout << "There is no longer any magic here..." << std::endl;
    }

}

void Room::PrintEnterRoom(const Player& aPlayer) const
{
    system("cls");
    std::cout << aPlayer.GetName() << '\t' <<
        " enters the... " << '\t' <<
        myName << '\n' << std::endl;
}
