#pragma once

namespace  Player
{
    struct Data
    {
        int myMoney = 99999;
        const int streakArrayMax = 5;
        int  winStreak[5] = {0};
        bool isWin = {};
        bool isPoor = false;
        
        enum class Streak
        {
            Null,
            Win,
            Loss
        };
    };
};
