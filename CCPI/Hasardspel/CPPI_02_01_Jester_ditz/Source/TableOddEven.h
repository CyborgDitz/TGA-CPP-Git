#pragma once
#include "Player.h"
#include "Data.h"
namespace TableOddEven
{
    struct Data
    {
        enum class OddCoin
        {
            No_Coin,
            Odd,
            Even
        };
        int myMoney = {100};
        int myTreshBig = 200;
        int myTreshSmall = 50;
        int myTableMultiplier =3;
        int myTableBonus = 55;
        const int inputTableMin {};
        const int inputTableMax {};
    };
    Data::OddCoin CalcOddEven();
    void PlayTable(Player::Data& aPlayer);
}
