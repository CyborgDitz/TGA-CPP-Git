#include "TableRoulette.h"
#include "TableRoulette.h"
#include "TableRoulette.h"
#include <iostream>
#include <ostream>
#include "Data.h"
#include "Casino.h"
#include "Player.h"

namespace TableRoulette
{
    void PlayStraight(Player::Data& aPlayer, Data& aRoulette)
    {

        bool isInputActive = true;
        const int die1 = Casino::RollRoulette();
        const int DiceSum = die1;

        int playerGuess = Casino::InputInt();

        while (isInputActive)
        {

            if (aRoulette.mySlotsMin <= playerGuess && playerGuess <= aRoulette.mySlotsMax)
            {
                std::cout << "Gotcha!" << std::endl;
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
        std::cout << "I spun the ball on: " << die1 << std::endl;
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
    void PlayColumn(Player::Data& aPlayer, Data::Column& aColumn)
    {
        const int divideToThirds = 2;
        int randomColumn = Casino::RollDie() / divideToThirds;
        if (aColumn == Data::Column::Left)
        {
            std::cout << "It was LEFT " << std::endl;
        }
        else if (aColumn == Data::Column::Middle)
        {
            std::cout << "It was the MIDDLE" << std::endl;
        }
        else
        {
            std::cout << "It was RIGHT" << std::endl;
        }
        const int aColumnValue = static_cast<int>(aColumn);

        if (aColumnValue != randomColumn)
        {
            Casino::SayLose();
            aPlayer.isWin = false;
        }
        else
        {
            aPlayer.isWin = true;
            Casino::SayWin();
        }
    }
    void RouletteBet(Player::Data& aPlayer, Data& aRoulette, Data::Bets& aBet)
    {
        bool isBetting = true;
        std::cout << "Pick what you want to bet on!\n 1. Straight\t2. Red/Black\n 3. Odd/Even\t4. Column bet!!" << std::endl;
        while (isBetting)
        {
            switch (static_cast<Data::Bets>(Casino::InputInt()))
            {
                case Data::Bets::Invalid:
                {
                    std::cout << "Nope, you have to bet" << std::endl;
                    break;
                }
                case Data::Bets::Straight_Gay:
                {
                    aBet = Data::Bets::Straight_Gay;
                    std::cout << "What are you betting on of 0-36?" << std::endl;
                    PlayStraight(aPlayer, aRoulette);
                    isBetting = false;

                    break;
                }

                case Data::Bets::Red_Black:
                {
                    aBet = Data::Bets::Red_Black;
                    std::cout << "Are you betting 1. Red or  2. Black" << std::endl;
                    Data::Color color = static_cast<Data::Color>(Casino::InputInt());
                    switch (color)
                    {
                        case Data::Color::Red:
                        {
                            std::cout << "You picked red!" << std::endl;
                            break;
                        }
                        case Data::Color::Black:
                        {

                            std::cout << "You picked red!" << std::endl;
                            break;
                        }
                        case Data::Color::Green:
                        default:
                        {
                            std::cout << "No!" << std::endl;
                            break;
                        }
                    }
                    PlayRouColorOrOdd(aPlayer, color);
                    isBetting = false;
                    break;
                }
                case Data::Bets::Odd_Even:
                {
                    aBet = Data::Bets::Odd_Even;
                    std::cout << "Are you betting 1. Odd or  2. Even?" << std::endl;
                    Data::Color colorAndNumber = static_cast<Data::Color>(Casino::InputInt());
                    switch (colorAndNumber)
                    {
                        case Data::Color::Black:
                        {
                            std::cout << "Odd!!" << std::endl;
                            break;
                        }
                        case Data::Color::Red:
                        {
                            std::cout << "Even!" << std::endl;
                            break;
                        }
                        case Data::Color::Green:
                        default:
                        {
                            std::cout << "No!" << std::endl;
                            break;
                        }

                    }
                    PlayRouColorOrOdd(aPlayer, colorAndNumber);
                    isBetting = false;
                    break;
                }
                case Data::Bets::Column:
                {
                    aBet = Data::Bets::Column;
                    std::cout << "What colum are you betting on?\n 1. left\t2. middle\t3. right" << std::endl;
                    Data::Column column = static_cast<Data::Column>(Casino::InputInt());

                    PlayColumn(aPlayer, column);
                    isBetting = false;

                    break;
                }
            }
        }
    }
    void PlayRouColorOrOdd(Player::Data& aPlayer, Data::Color& aColor)
    {
        {
            if (aColor != CalcRouletteColorAndOdd())
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

    Data::Color CalcRouletteColorAndOdd()
    {
        Data::Color returnValue = {};
        const int die = Casino::RollRoulette();
        if (die % 2 == 1)
        {
            std::cout << "It is Red indeed!" << std::endl;
            returnValue = Data::Color::Red;
        }
        else if (die % 2 == 0)
        {
            std::cout << "It is Black indeed!" << std::endl;
            returnValue = Data::Color::Black;
        }
        else
        {
            std::cout << "It is a zero! oof!" << std::endl;
            returnValue = Data::Color::Green;
        }
        return returnValue;
    }
    void PlayTable(Player::Data& aPlayer, Data& aRoulette, Data::Bets& aBet)
    {
        RouletteBet(aPlayer, aRoulette, aBet);
    }
}
