#pragma once

namespace  Player
{
    struct Data
    {
        int myMoney = 99999;
        const int streakArrayMax = 5;
        char winStreak[5] = {};
        bool isWin = {};
        bool isPoor = false;
    };
};
