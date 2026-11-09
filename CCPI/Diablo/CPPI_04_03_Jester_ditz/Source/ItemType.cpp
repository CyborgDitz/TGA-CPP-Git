#include "ItemType.h"

#include <iostream>


ItemType::ItemType() { }

ItemType::ItemType(const char* aName, int aMainMod, int aSecondMod)
{
    strcpy_s(myName, aName);
    myMainMod = aMainMod;
    mySecondMod = aSecondMod;
}

void ItemType::PrintStats() const
{
    std::cout << "The Item - " << myName << " - stats are : \n" <<
        "Affects MainStat by: " << myMainMod << '\t' <<
        "Affects Secondary Stat by: " << mySecondMod << '\n' << std::endl;
}
