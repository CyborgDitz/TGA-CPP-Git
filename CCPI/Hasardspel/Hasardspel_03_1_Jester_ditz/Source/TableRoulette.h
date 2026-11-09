#pragma once
#include <iostream>

#include "Casino.h"
#include "Player.h"

namespace TableRoulette
{
    struct Data
    {
        int myMoney = {1000};
        int myTreshBig = 2000;
        int myTreshSmall = 500;
        int myStraighGayMult = 35;
        int myRedBlackMult = 3;
        int myOddEvenMult = 1;
        int myColumnMult = 2;
        int mySlotsMax = 36;
        int mySlotsMin = 0;
        
        enum class Color
        {
            Green = 0,
            Red = 1,
            Black = 2
        };
        enum class Bets
        {
            Invalid = 0,
            Straight_Gay = 1,
            Red_Black = 2,
            Odd_Even = 3,
            Column = 4
        };
        enum class Column
        {
            Left = 1,
            Middle = 2,
            Column_Three = 3
        };
    };
    Data::Color CalcRouletteColorAndOdd();
    void PlayColumn(Player::Data& data,  Data::Column& aColumn);
    void PlayRouColorOrOdd(Player::Data& aPlayer, Data::Color& aColor);
    void PlayTable(Player::Data& aPlayer, Data& aRoulette, Data::Bets& aBets);
    void RouletteBet(Player::Data& aPlayer,  Data& aRoulette, Data::Bets& aBets);
    void PlayStraight(Player::Data& aPlayer, Data& aRoulette);
};
