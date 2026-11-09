#pragma once

namespace Casino
{
    void SayInputError();
    int InputInt();
    int RollDie();
    void SayWin();
    void SayLose();
    struct Data
    {
        bool isMainActive = false;
        bool IsTableActive = false;
    };
};
