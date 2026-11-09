#include "ItemFactory.h"

ItemFactory::ItemFactory() = default;
ItemFactory::~ItemFactory() { }

void ItemFactory::Init()
{
    const int itemHammer = static_cast<int>(enumItemType::Hammer);
    myItemTypes[itemHammer].SetName("Blob Hammer");
    myItemTypes[itemHammer].SetMainMod(3);
    myItemTypes[itemHammer].SetSecondMod(2);
    myItemTypes[itemHammer].SetWeight(45);


    const int itemSword = static_cast<int>(enumItemType::Sword);
    myItemTypes[itemSword].SetName("Slime sword");
    myItemTypes[itemSword].SetMainMod(10);
    myItemTypes[itemSword].SetWeight(2);

    const int itemHorn = static_cast<int>(enumItemType::Horn);
    myItemTypes[itemHorn].SetName("The Horn of Doom and Slimery");
    myItemTypes[itemHorn].SetMainMod(666);
    myItemTypes[itemHorn].SetWeight(1);
}

Item ItemFactory::CreateItem(const enumItemType aItemType) const
{
    Item newItem(myItemTypes[static_cast<int>(aItemType)]);
    return newItem;
}
