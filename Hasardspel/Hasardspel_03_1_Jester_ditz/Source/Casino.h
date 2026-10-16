#pragma once

namespace Casino
{
    void SayInputError();
    int InputInt();
    int RollDie();
    int RollRoulette();
    void SayWin();
    void SayLose();
    struct Data
    {
        enum class OddCoin
        {
            No_Coin,
            Odd,
            Even
        };
        bool isMainActive = false;
        bool IsTableActive = false;
    };
   Data::OddCoin CalcOddEven();
    enum class TableMenu
    {
        Exit_Table,
        BeginGame,
        Print_Rules,
        Print_Streak,
    };
    enum class GameState
    {
        Exit_Main,
        Table_Guess,
        Table_OddEven,
        Table_HighRoll,
        Table_Roulette,
        Winstreak
    };
};
