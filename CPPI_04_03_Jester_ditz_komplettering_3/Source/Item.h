#pragma once
#include "ItemType.h"

enum class enumItemType
{
    Hammer,
    Sword,
    Horn,
    Count
};

class Item
{
public:
    Item() = delete;
    Item(const ItemType& aItemType);

    int GetMainMod() const;
    int GetSecondMod() const;
    int GetWeight() const;
    const char* GetName() const;

private:
    const ItemType* myItemType;
};
