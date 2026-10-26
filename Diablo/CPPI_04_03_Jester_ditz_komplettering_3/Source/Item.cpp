#include "Item.h"


Item::Item(const ItemType& aItemType) : myItemType(&aItemType) { }

int Item::GetMainMod() const
{
    return myItemType->GetMainMod();
}

int Item::GetSecondMod() const
{
    return myItemType->GetSecondMod();
}

int Item::GetWeight() const
{
    return myItemType->GetWeight();
}

const char* Item::GetName() const
{
    return myItemType->GetName();
}
