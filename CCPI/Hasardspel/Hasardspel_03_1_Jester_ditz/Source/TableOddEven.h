#pragma once
#include "Player.h"
#include "Data.h"
namespace TableOddEven
{
    struct Data
    {
        
        int myMoney = {100};
        int myTreshBig = 200;
        int myTreshSmall = 50;
        int myTableMultiplier =3;
        int myTableBonus = 55;
    };
    void PlayTable(Casino::GameState& aGameState, Player::Data& aPlayer);
}
