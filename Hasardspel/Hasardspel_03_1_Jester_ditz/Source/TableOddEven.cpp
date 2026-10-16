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
  
    void PlayTable(Casino::GameState& aGameState, Player::Data& aPlayer)
    {
        {
            bool isInputActive = true;
           Casino::Data::OddCoin playerGuess = {};
            while (isInputActive)
            {
                SayRulesTable(aGameState);
                playerGuess = static_cast<Casino::Data::OddCoin>(Casino::InputInt() );
                if (playerGuess == Casino::Data::OddCoin::Odd || playerGuess == Casino::Data::OddCoin::Even)
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

            if (playerGuess != Casino::CalcOddEven() )
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
