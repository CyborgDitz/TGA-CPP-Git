#pragma once
#include "Casino.h"
#include "Data.h"
#include "Player.h"
namespace TableGuess
{
    void PlayTable(Casino::GameState& aGameState, Player::Data& aPlayer);
    struct Data
    {
        int myMoney = {100};
        int myTreshBig = 200;
        int myTreshSmall = 50;
        int myTableMultiplier = 2;
        int myTableBonus = 0;
        const int inputTableMin = 2;
        const int inputTableMax = 12;
    };
}
