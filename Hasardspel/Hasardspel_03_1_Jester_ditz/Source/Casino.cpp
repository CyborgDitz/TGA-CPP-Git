#include "Casino.h"

#include <iostream>
#include <random>
namespace Casino
{
    int InputInt()
    {
        int playerInput = {};
        int returnValue{};
        bool isInputActive = true;
        while (isInputActive)
        {
            std::cin >> playerInput;

            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                SayInputError();
                //TODO input min and Max
            }
            else
            {
                returnValue = playerInput;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                isInputActive = false;
            }
        }

        return returnValue;
    }
    int RollDie()
    {
        std::random_device seed;
        std::mt19937 rndEngine(seed());
        std::uniform_int_distribution<int> rndDist(1, 6);
        int randomNumber = rndDist(rndEngine);
        return randomNumber;
    };
    int RollRoulette()
    {
        std::random_device seed;
        std::mt19937 rndEngine(seed());
        std::uniform_int_distribution<int> rndDist(0, 36);
        int randomNumber = rndDist(rndEngine);
        return randomNumber;
    };
    void SayWin()
    {
        std::cout << "You win!" << std::endl;
    }
    void SayLose()
    {
        std::cout << "Thats your loss, you unlucky fool! \n" << std::endl;
    }
    void SayInputError()
    {
        std::cout << "wrong input!" << std::endl;
    }
    Data::OddCoin CalcOddEven()
    {
        const int die = RollDie();
        if (die % 2 == 1)
        {
            std::cout << "It is Odd!" << std::endl;
            return Data::OddCoin::Odd;
        }
        else
        {
            std::cout << "It is Even!" << std::endl;
            return Data::OddCoin::Even;
        }
    }
}