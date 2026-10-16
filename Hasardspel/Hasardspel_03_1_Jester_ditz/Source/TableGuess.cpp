#include "TableGuess.h"
#include <iostream>
#include <ostream>
#include "Data.h"
#include "Casino.h"
#include "Hasardspel.h"

namespace TableGuess
{
    void PlayTable(Casino::GameState& aGameState, Player::Data& aPlayer)
    {
        Data tableData;
        int playerGuess = 0;
        bool isInputActive = true;
        const int die1 = Casino::RollDie();
        const int die2 = Casino::RollDie();
        const int DiceSum = die1 + die2;
        while (isInputActive)
        {
            SayRulesTable(aGameState);
            playerGuess = Casino::InputInt();
            if (tableData.inputTableMin <= playerGuess && playerGuess <= tableData.inputTableMax)
            {
                isInputActive = false;
            }
            //cheat  codes to win, input 69 or 67
            else if (playerGuess == 69 || playerGuess == 67)
            {
                playerGuess = DiceSum;
                isInputActive = false;
            }
            else
            {
                isInputActive = true;
            }
        }
        std::cout << "I rolled: " << die1 << " and " << die2 << '\n'
            << "Sum: " << die1 + die2 << '\n' << std::endl;
        if (playerGuess != DiceSum)
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
