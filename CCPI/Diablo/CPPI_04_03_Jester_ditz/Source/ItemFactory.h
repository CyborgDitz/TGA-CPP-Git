#pragma once
#include <array>

#include "Item.h"
#include "ItemType.h"

class ItemFactory
{
public:
    ItemFactory();
    ~ItemFactory();
    void Init();
    Item CreateItem(const enumItemType aItemType) const;

private:
    std::array<ItemType, static_cast<int>(enumItemType::Count)> myItemTypes;
};
