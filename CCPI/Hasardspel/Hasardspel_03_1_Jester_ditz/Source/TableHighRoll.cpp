
#include "TableHighRoll.h"
#include <cstdlib>
#include <iostream>
#include "Casino.h"
#include "Data.h"

namespace TableHighRoll
{
    void PlayTable(Player::Data& aPlayer)
    {
        {
            int differenceValue;

            SayAskReadyToRoll();
            system("pause");
            const int playerDie1 = Casino::RollDie();
            const int playerDie2 = Casino::RollDie();
            const int playerDiceSum = playerDie1 + playerDie2;

            std::cout << "YOU rolled: " << playerDie1 << " and " << playerDie2 << '\n'
                << "Sum: " << playerDiceSum << '\n' << std::endl;
            int die1 = Casino::RollDie();
            int die2 = Casino::RollDie();
            int diceSum = die1 + die2;

            std::cout << "I rolled: " << die1 << " and " << die2 << '\n'
                << "Sum: " << diceSum << '\n' << std::endl;

            if (playerDiceSum <= diceSum)
            {
                aPlayer.isWin = false;
                differenceValue = diceSum - playerDiceSum;
                std::cout << "It differs by: " << differenceValue << std::endl;
                std::cout << "Yours is not bigger than mine!!" << std::endl;
                Casino::SayLose();
            }
            else if (playerDiceSum > diceSum)
            {
                aPlayer.isWin = true;
                differenceValue = playerDiceSum - diceSum;
                std::cout << "It differs by: " << differenceValue << std::endl;
                std::cout << "Yours is bigger than mine!" << std::endl;
                Casino::SayWin();
            }
        }
    }
    void SayAskReadyToRoll()
    {
        std::cout << "Are you ready to start? Press any button to begin" << std::endl;
    }
}
