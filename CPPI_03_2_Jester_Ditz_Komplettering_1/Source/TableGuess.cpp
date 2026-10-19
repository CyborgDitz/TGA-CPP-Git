#include "TableGuess.h"

#include <iostream>


void TableGuess::SayGuessTreshHold()
{
    if (myMoney >= myTreshLoser)
    {
        std::cout << "Try again, regain your losses!?" << std::endl;
    }
    else if (myMoney <= myTreshWinning)
    {
        std::cout << "We have a big winner here, why quit when the fire is hot amiright?" << std::endl;
    }
    else
    {
        std::cout << "You should  spend that money here and nowhere else!" << std::endl;
    }
}

void TableGuess::SayGuessRules()
{
    std::cout << "The table is open! So give me one between " << myBetMin <<" and " << myBetMax << "! Lets gamble!" << std::endl;
}
