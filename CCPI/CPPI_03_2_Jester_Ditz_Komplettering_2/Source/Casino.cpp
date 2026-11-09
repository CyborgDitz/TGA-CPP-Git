#include "Casino.h"
#include <iostream>
#include <random>
#include "TableRoulette.h"
#include "TableHighRoll.h"
#include <cstdlib>
#include "TableGuess.h"


void Casino::SayInputError()
{
    std::cout << "wrong input!" << std::endl;
}

void Casino::PlayTableOddEven(Casino& aCasino)
{
    {
        bool isInputActive = true;
        OddCoin playerGuess = {};
        while (isInputActive)
        {
            aCasino.SayRulesTable();
            playerGuess = static_cast<OddCoin>(aCasino.InputInt());
            if (playerGuess == OddCoin::Odd || playerGuess == OddCoin::Even)
            {
                isInputActive = false;
            }
            else
            {
                aCasino.SayInputError();
            }
        }

        const int die = aCasino.RollDie();
        const int die2 = aCasino.RollDie();
        int sum = die + die2;
        std::cout << "I rolled: " << die << "+ " << die2 << std::endl;

        if (playerGuess != aCasino.CalcOddEven(sum))
        {
            aCasino.GetPlayer().SetIsWin(false);
            aCasino.SayLose(aCasino);
        }
        else
        {
            aCasino.GetPlayer().SetIsWin(true);
            aCasino.SayWin(aCasino);
        }
    }
}

void Casino::PlayTableGuess(Casino& aCasino)
{
    int playerGuess = 0;
    bool isInputActive = true;
    const int die1 = aCasino.RollDie();
    const int die2 = aCasino.RollDie();
    const int DiceSum = die1 + die2;

    while (isInputActive == true)
    {
        const int inputMin = 2;
        const int inputMax = 12;
        std::cout << "Pick a sum between " << inputMin << " and " << inputMax << std::endl;
        playerGuess =aCasino.InputInt();
        if (inputMin <= playerGuess && playerGuess <= inputMax)
        {
            isInputActive = false;
        }
    }

    aCasino.SayRulesTable();
    std::cout << "I rolled: " << die1 << " and " << die2 << '\n'
        << "Sum: " << die1 + die2 << '\n' << std::endl;
    if (playerGuess != DiceSum)
    {
        aCasino.GetPlayer().SetIsWin(false);
        aCasino.SayLose(aCasino);
    }
    else
    {
        aCasino.GetPlayer().SetIsWin(true);
        aCasino.SayWin(aCasino);
    }
}

void Casino::PlayTableHighRoll(Casino& aCasino)
{
    int differenceValue;

    aCasino.SayAskReadyToRoll(aCasino);
    system("pause");
    int playerDie1 = aCasino.RollDie();
    int playerDie2 = aCasino.RollDie();
    int playerDiceSum = playerDie1 + playerDie2;

    std::cout << "YOU rolled: " << playerDie1 << " and " << playerDie2 << '\n'
        << "Sum: " << playerDiceSum << '\n' << std::endl;
    int die1 = aCasino.RollDie();
    int die2 = aCasino.RollDie();
    int diceSum = die1 + die2;

    std::cout << "I rolled: " << die1 << " and " << die2 << '\n'
        << "Sum: " << diceSum << '\n' << std::endl;

    if (playerDiceSum <= diceSum)
    {
        aCasino.GetPlayer().SetIsWin(false);
        differenceValue = diceSum - playerDiceSum;
        std::cout << "It differs by: " << differenceValue << std::endl;
        aCasino.GetPlayer().SayName();
        std::cout << "'s is not bigger than mine!!" << std::endl;
        aCasino.SayLose(aCasino);
    }
    else if (playerDiceSum > diceSum)
    {
        aCasino.GetPlayer().SetIsWin(true);
        differenceValue = playerDiceSum - diceSum;
        std::cout << "It differs by: " << differenceValue << std::endl;
        std::cout << "Yours is bigger than mine!" << std::endl;
        aCasino.SayWin(aCasino);
    }
}

void Casino::CalcRouletteColorAndOdd(Casino& aCasino)
{
    int die = aCasino.RollRoulette();
    if (die % 2 == 1)
    {
        std::cout << "It is Red!" << std::endl;
        aCasino.GetTableRoulette().SetColor(TableRoulette::Color::Red);
    }
    else if (die % 2 == 0)
    {
        std::cout << "It is Black!" << std::endl;
        aCasino.GetTableRoulette().SetColor(TableRoulette::Color::Black);
    }
    else
    {
        std::cout << "It is a zero! oof!" << std::endl;
        aCasino.GetTableRoulette().SetColor(TableRoulette::Color::Green);
    }
}


void Casino::PlayStraight(Casino& aCasino)
{
    bool isInputActive = true;
    int die1 = aCasino.RollRoulette();
    int DiceSum = die1;

    int playerGuess{};

    while (isInputActive)
    {
        playerGuess = aCasino.InputInt();
        if (aCasino.GetTableRoulette().GetSlotsMin() <= playerGuess && playerGuess <= aCasino.GetTableRoulette().
            GetSlotsMax())
        {
            std::cout << "Gotcha!" << std::endl;
            isInputActive = false;
        }
        //cheat  codes to win, input 69 or 67
        else if (playerGuess == 69 || playerGuess == 67)
        {
            playerGuess = DiceSum;
            isInputActive = false;
        }
        else
        {
            std::cout << "value must be between " << aCasino.GetTableRoulette().GetSlotsMin() << " and " << aCasino.
                GetTableRoulette().GetSlotsMax() << std::endl;
            isInputActive = true;
        }
    }
    std::cout << "I spun the ball on: " << die1 << std::endl;
    if (playerGuess != DiceSum)
    {
        aCasino.GetPlayer().SetIsWin(false);
        aCasino.SayLose(aCasino);
    }
    else
    {
        aCasino.GetPlayer().SetIsWin(true);
        aCasino.SayWin(aCasino);
    }
}

void Casino::PlayColumn(Casino& aCasino)
{
    int divideToThirds = 2;
    int randomColumn = aCasino.RollDie() / divideToThirds;
    if (aCasino.GetTableRoulette().GetColumn() == TableRoulette::Column::Left)
    {
        std::cout << "It was LEFT " << std::endl;
    }
    else if (aCasino.GetTableRoulette().GetColumn() == TableRoulette::Column::Middle)
    {
        std::cout << "It was the MIDDLE" << std::endl;
    }
    else
    {
        std::cout << "It was RIGHT" << std::endl;
    }
    int aColumnValue = static_cast<int>(aCasino.GetTableRoulette().GetColumn());

    if (aColumnValue != randomColumn)
    {
        aCasino.SayLose(aCasino);
        aCasino.GetPlayer().SetIsWin(false);
    }
    else
    {
        aCasino.GetPlayer().SetIsWin(true);
        aCasino.SayWin(aCasino);
    }
}

void Casino::RouletteBet(Casino& aCasino)
{
    bool isBetting = true;
    std::cout << "Pick what you want to bet on, ";
    aCasino.GetPlayer().SayName();
    std::cout << "?\n 1. Straight\t2. Red/Black\n 3. Odd/Even\t4. Column bet!!" <<
        std::endl;
    while (isBetting)
    {
        TableRoulette::Bet bet = static_cast<TableRoulette::Bet>(aCasino.InputInt());
        aCasino.GetTableRoulette().SetBets(bet);
        switch (aCasino.GetTableRoulette().GetBets())
        {
        case TableRoulette::Bet::Invalid :
            {
                std::cout << "Nope, you have to bet";
                aCasino.GetPlayer().SayName();
                std::cout << std::endl;
                break;
            }
        case TableRoulette::Bet::Straight_Gay :
            {
                std::cout << "What are you betting on of 0-36";
                aCasino.GetPlayer().SayName();
                std::cout << "?" << std::endl;
                PlayStraight(aCasino);
                isBetting = false;

                break;
            }

        case TableRoulette::Bet::Red_Black :
            {
                std::cout << "Are you betting 1. Red or  2. Black";
                aCasino.GetPlayer().SayName();
                std::cout << "?" << std::endl;
                TableRoulette::Color color = static_cast<TableRoulette::Color>(aCasino.InputInt());
                switch (color)
                {
                case TableRoulette::Color::Red :
                    {
                        std::cout << "You picked red";
                        aCasino.GetPlayer().SayName();
                        std::cout << "!" << std::endl;
                        break;
                    }
                case TableRoulette::Color::Black :
                    {
                        std::cout << "You picked red";
                        aCasino.GetPlayer().SayName();
                        std::cout << "!" << std::endl;
                        break;
                    }
                case TableRoulette::Color::Green :
                default :
                    {
                        std::cout << "No!" << std::endl;
                        break;
                    }
                }
                PlayRouColorOrOdd(aCasino, color);
                isBetting = false;
                break;
            }
        case TableRoulette::Bet::Odd_Even :
            {
                std::cout << "Are you betting 1. Odd or  2. Even";
                aCasino.GetPlayer().SayName();
                std::cout << "?" << std::endl;
                TableRoulette::Color colorAndNumber = static_cast<TableRoulette::Color>(aCasino.InputInt());
                switch (colorAndNumber)
                {
                case TableRoulette::Color::Black :
                    {
                        std::cout << "Odd!!" << std::endl;
                        break;
                    }
                case TableRoulette::Color::Red :
                    {
                        std::cout << "Even!" << std::endl;
                        break;
                    }
                case TableRoulette::Color::Green :
                default :
                    {
                        std::cout << "No!" << std::endl;
                        break;
                    }
                }
                PlayRouColorOrOdd(aCasino, colorAndNumber);
                isBetting = false;
                break;
            }
        case TableRoulette::Bet::Column :
            {
                aCasino.GetTableRoulette().SetBets(TableRoulette::Bet::Column);
                std::cout << "What colum are you betting on?\n 1. left\t2. middle\t3. right" << std::endl;


                PlayColumn(aCasino);
                isBetting = false;

                break;
            }
        }
    }
}

void Casino::PlayRouColorOrOdd(Casino& aCasino, const TableRoulette::Color& aColor)
{
    CalcRouletteColorAndOdd(aCasino);
    if (aColor != aCasino.GetTableRoulette().GetColor())
    {
        aCasino.GetPlayer().SetIsWin(false);
        aCasino.SayLose(aCasino);
    }
    else
    {
        aCasino.GetPlayer().SetIsWin(true);
        aCasino.SayWin(aCasino);
    }
}

int Casino::InputInt()
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

void Casino::SayRulesTable()
{
    switch (gameState)
    {
    case GameState::Table_Guess_LowStake :
        {
            tableGuess.SayGuessRules();
            break;
        }
    case GameState::Table_Guess_HighStake :
        {
            tableGuess2.SayGuessRules();
            break;
        }
    case GameState::Table_OddEven :
        {
            std::cout << "The table is open! So guess if its 1: Odd, 2: even! 50 50!" << std::endl;
            break;
        }
    case GameState::Table_HighRoll :
        {
            std::cout << "Just roll higher than me!";
            GetPlayer().SayName();
            std::cout << "!" << std::endl;
            break;
        }
    case GameState::Table_Roulette :
        {
            std::cout << "There are four bet types: \n"
                << "1. Straight, guess a the number the ball lands on, between 0 and 36\n" <<
                "2. Red or Black, guess the color of the number the ball lands on! However, the 0 is green and you cant guess that. \n"
                <<
                "3. Odd or Even, guess if the number is odd or even! However, the 0 doesnt count as either!" <<
                "4. Column Bet, there are three columns where the ball can land on.\n " <<
                "Left, middle, or right. The numbers are shown here (insert picture)" << std::endl;

            break;
        }
    case GameState::Exit_Main :
    case GameState::Winstreak :
    default :
        {
            SayInputError();
            break;
        }
    }
}

void Casino::SayAskReadyToRoll(Casino& aCasino)
{
    std::cout << "Are you ready to start? Press any button to begin";
    aCasino.GetPlayer().SayName();
    std::cout << "!" << std::endl;
}

TableRoulette::Color CalcRouletteColorAndOdd(Casino& aCasino)
{
    TableRoulette::Color returnValue = {};
    int die = aCasino.RollRoulette();
    if (die % 2 == 1)
    {
        std::cout << "It is Red indeed!" << std::endl;
        returnValue = TableRoulette::Color::Red;
    }
    else if (die % 2 == 0)
    {
        std::cout << "It is Black indeed!" << std::endl;
        returnValue = TableRoulette::Color::Black;
    }
    else
    {
        std::cout << "It is a zero! oof!" << std::endl;
        returnValue = TableRoulette::Color::Green;
    }
    return returnValue;
}

void Casino::AddTableMoney(const int aMoney)
{
    if (gameState == GameState::Table_Guess_LowStake)
    {
        tableGuess.AddMoney(aMoney);
    }
    else if (gameState == GameState::Table_OddEven)
    {
        tableOddEven.AddMoney(aMoney);
    }
    else if (gameState == GameState::Table_HighRoll)
    {
        tableHighRoll.AddMoney(aMoney);
    }
    else if (gameState == GameState::Table_Roulette)
    {
        tableRoulette.AddMoney(aMoney);
    }
}

void Casino::SubTableMoney(const int aMoney)
{
    if (gameState == GameState::Table_Guess_LowStake)
    {
        tableGuess.SubMoney(aMoney);
    }
    else if (gameState == GameState::Table_OddEven)
    {
        tableOddEven.SubMoney(aMoney);
    }
    else if (gameState == GameState::Table_HighRoll)
    {
        tableHighRoll.SubMoney(aMoney);
    }
    else if (gameState == GameState::Table_Roulette)
    {
        tableRoulette.SubMoney(aMoney);
    }
}

Casino::OddCoin Casino::CalcOddEven(const int aDieSum)
{
    if (aDieSum % 2 == 1)
    {
        std::cout << "It is Odd!" << std::endl;
        SetOddCoin(OddCoin::Odd);
    }
    else
    {
        std::cout << "It is Even!" << std::endl;
        SetOddCoin(OddCoin::Even);
    }
    return GetOddCoin();
}

int Casino::RollDie()
{
    std::random_device seed;
    std::mt19937 rndEngine(seed());
    std::uniform_int_distribution<int> rndDist(1, 6);
    int randomNumber = rndDist(rndEngine);
    return randomNumber;
};

int Casino::RollRoulette()
{
    std::random_device seed;
    std::mt19937 rndEngine(seed());
    std::uniform_int_distribution<int> rndDist(0, 36);
    int randomNumber = rndDist(rndEngine);
    return randomNumber;
};

void Casino::SayWin(Casino& aCasino)
{
    aCasino.GetPlayer().SayName();
    std::cout << ", you win!" << std::endl;
}

void Casino::SayLose(Casino& aCasino)
{
    std::cout << "Thats your loss ";
    aCasino.GetPlayer().SayName();
    std::cout << " you unlucky fool! \n" << std::endl;
}
