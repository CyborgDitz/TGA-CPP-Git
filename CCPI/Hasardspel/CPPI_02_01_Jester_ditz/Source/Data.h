#pragma once
#include <random>

namespace Data
{
    
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
        Winstreak
    };
   
}
