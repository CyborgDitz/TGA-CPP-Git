#include "TableGuess.h"
#include <iostream>

#include "TableOddEven.h"

#include "Casino.h"
#include "Hasardspel.h"

namespace TableOddEven
{
    void SayAskReadyToRoll()
    {
        std::cout << "Ready to roll? Press any key to GO!" << std::endl;
    }
    Data::OddCoin CalcOddEven()
    {
        const int die = Casino::RollDie();
        if (die % 2 == 1)
        {
            std::cout << "It is Odd!" << std::endl;
            return Data::OddCoin::Odd;
        }
        else
        {
            std::cout << "It is Even!" << std::endl;
            return Data::OddCoin::Even;
        }
    }
    void PlayTable(Player::Data& aPlayer)
    {
        {
            bool isInputActive = true;
           Data::OddCoin playerGuess = {};
            while (isInputActive)
            {
                playerGuess = static_cast<Data::OddCoin>(Casino::InputInt() );
                if (playerGuess == Data::OddCoin::Odd || playerGuess == Data::OddCoin::Even)
                {
                    isInputActive = false;
                }
                else
                {
                    Casino::SayInputError();
                }
            }

            const int die = Casino::RollDie();
            std::cout << "I rolled: " << die << std::endl;

            if (playerGuess != CalcOddEven() )
            {
                aPlayer.isWin = false;
                Casino::SayLose();
            }
            else
            {
                aPlayer.isWin = true;
                Casino::SayWin();
            }
        }
    }   
}
