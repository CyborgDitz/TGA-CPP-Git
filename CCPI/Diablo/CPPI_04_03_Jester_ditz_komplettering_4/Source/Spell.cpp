#include "Spell.h"

#include <iostream>

void Spell::PrintStats() const
{
    std::cout << "The Item - " << myName << " - stats are : \n" <<
        "Affects MainStat by: " << myMainMod << '\t' <<
        "Affects Secondary Stat by: " << mySecondMod << '\n' << std::endl;
}
