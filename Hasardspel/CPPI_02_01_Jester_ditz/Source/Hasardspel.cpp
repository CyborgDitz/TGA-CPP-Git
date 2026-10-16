#pragma once
#include <iostream>
#include <random>
#include <cstdlib>
#include "Data.h"
#include "Hasardspel.h"
#include "TableGuess.h"
#include "TableOddEven.h"
#include "TableHighRoll.h"

void SayEnterCasino()
{
    std::cout << "Welcome to the Casino, friend! \n" << std::endl;
    std::cout << "What would you like to do? \n" << std::endl;
}
void SayTableMenu()
{
    std::cout << "1: Play the game. \t 2: Show Rules.\n" "3: Show Win Streak \t 0: Leave and go back to Main Menu" << std::endl;
};
void SayTableOutCashed()
{
    std::cout << "You have claimed too much of this table, begone!" << std::endl;
}
void SayPlayAgain()
{
    std::cout << "Want to play again? Y or N?" << std::endl;
}
void SayTableTreshold(const Data::GameState& aGameState, 
    TableGuess::Data& aGuess, TableOddEven::Data& aOddEven, TableHighRoll::Data& aHighRoll)
{
    // debug SayTableSpoils(aGameState);
    // optimizable cases for multiple usage of code (bools), use for loop if true with enum
    switch (aGameState)
    {
        case Data::GameState::Table_Guess:
        {
            if ( aGuess.myMoney> aGuess.myTreshBig)
            {
                std::cout << "We have a big winner here, why quit when the fire is hot amiright?" << std::endl;
            }
            else if (aGuess.myMoney> aGuess.myTreshSmall)
            {
                std::cout << "Try again, regain your losses!?" << std::endl;
            }
            else
            {
                std::cout << "You should  spend that myMoney here and nowhere else!" << std::endl;
            }
            break;
        }
        case Data::GameState::Table_OddEven:
        {
            if (aOddEven.myMoney > aOddEven.myTreshBig)
            {
                std::cout << "We have a big winner here, why quit when the fire is hot amiright?" << std::endl;
            }
            else if (aOddEven.myMoney > aOddEven.myTreshSmall)
            {
                std::cout << "Try again, regain your losses!?" << std::endl;
            }
            else
            {
                std::cout << "You should  spend that myMoney here and nowhere else!" << std::endl;
            }
            break;
        }
        case Data::GameState::Table_HighRoll:
        {
            if (aHighRoll.myMoney <= aHighRoll.myTreshBig)
            {
                std::cout << "We have a big winner here, why quit when the fire is hot amiright?" << std::endl;
            }
            else if (aHighRoll.myMoney > aHighRoll.myTreshBig)
            {
                std::cout << "Try again, regain your losses!?" << std::endl;
            }
            else
            {
                std::cout << "You should  spend that myMoney here and nowhere else!" << std::endl;
            }
            break;
        }
        case Data::GameState::Exit_Main:
        case Data::GameState::Winstreak:
        default:
        {
            break;
        }

    }
}

void SayByeCasino(Player::Data& aPlayer)
{
    SayMoneySum(aPlayer);
    std::cout << "Goodbye friend, and  good luck!" << std::endl;
    system("pause");
}
void SayRulesTable(Data::GameState& aGameState)
{
    switch (aGameState)
    {
        case Data::GameState::Table_Guess:
        {
            std::cout << "The table is open! So give me one between 2 and 12! Lets gamble!" << std::endl;
            break;
        }
        case Data::GameState::Table_OddEven:
        {
            std::cout << "The table is open! So guess if its 1: Odd, 2: even! 50 50!" << std::endl;
            break;
        }
        case Data::GameState::Table_HighRoll:
        {
            std::cout << "Just roll higher than me!" << std::endl;
            break;
        }
        case Data::GameState::Exit_Main:
        case Data::GameState::Winstreak:
        default:
        {
            Casino::SayInputError();
            break;
        }
    }
}
void SayMainMenuChoices()
{
    std::cout << "You can choose between these options \n"
        << "1: Table 1: Guess the Dice \t 2: Table 2: Odd or Even \n"
        << "3: Table 3: Roll Higher \t 4: Show Win / Loss Statistics\n"
        << "0: Or leave the casino!\n" << std::endl;
}

void SayGreetingTable(Data::GameState& aGameState)
{
    switch (aGameState)
    {
        case Data::GameState::Table_OddEven:
        {
            std::cout << "This is the best table for the best gambler, the guessing table! \n"
                << "If you guess the sum of my 2 dice then you win! \n" << std::endl;
            break;
        }
        case Data::GameState::Table_Guess:
        {
            std::cout << "Welcome to the odd or even table!" << std::endl;
            break;
        }
        case Data::GameState::Table_HighRoll:
        {
            std::cout << "Welcome to the simple Die Roll vs Den!" << std::endl;
            break;
        }
        case Data::GameState::Exit_Main:
            break;
        case Data::GameState::Winstreak:
            break;
        default:
        {
            break;
        }
    }
}
void SayMoneySum(const Player::Data& aPlayer)
{
    std::cout << "You currently have " << aPlayer.myMoney << " dollaridoos! \n";
}
void SayTableMoney(Data::GameState& aGameState, TableGuess::Data& aGuess, TableOddEven::Data& aOddEven, TableHighRoll::Data& aHighRoll)
{
    if (aGameState == Data::GameState::Table_Guess)
    {
        std::cout << "This table currently have " << aGuess.myMoney << " dollaridoos! \n";
    }
    else if (aGameState == Data::GameState::Table_OddEven)
    {
        std::cout << "This table currently have " << aOddEven.myMoney<< " dollaridoos!\n";
    }
    else if (aGameState == Data::GameState::Table_HighRoll)
    {
        std::cout << "This table currently have " << aHighRoll.myMoney << " dollaridoos! \n";
    }
}

void ExitMenu(Casino::Data& aCasino)
{
    if (aCasino.IsTableActive && aCasino.isMainActive)
    {
        aCasino.IsTableActive = false;
    }
    else if (aCasino.IsTableActive == false && aCasino.isMainActive)
    {
        aCasino.isMainActive = false;
    }
}
void PrintWinStreak(const Player::Data& aPlayer)
{
    const int length = sizeof(aPlayer.winStreak);
    std::cout << "Your win and loss score is: " << std::endl;
    for (int i = length; i > 0; i--)
    {
        std::cout << &aPlayer.winStreak[i];
    }
}
void UpdateWinStreak(bool aIsWin, Player::Data& aPlayer)
{
    char winValue;
    if (aIsWin == true)
    {
        winValue = 'W';
    }
    else
    {
        winValue = 'L';
    }

    int length = sizeof(*aPlayer.winStreak);
    for (int i = length; i > 0; i--)
    {
        aPlayer.winStreak[i + 1] = aPlayer.winStreak[i];
        aPlayer.winStreak[i] = winValue;
    }
    PrintWinStreak(aPlayer);
}
bool AmIPoor(Player::Data& aPlayer)
{
    if (aPlayer.myMoney <= 0 && aPlayer.isPoor == false)
    {
        std::cout << "Get out of our casino you dud!" << std::endl;
        aPlayer.isPoor = true;
        return true;
    }
    else
    {
        return false;
    }
   
}
bool IsTablePoor(const Data::GameState& aGameState,  const TableGuess::Data& aGuess, const TableOddEven::Data& aOddEven, const TableHighRoll::Data& aHighRoll)
{
    //TODO enum refactor
    int tableWinCap = 0;

    switch (aGameState)
    {
        case Data::GameState::Table_Guess:
        {
            if (aGuess.myMoney <= tableWinCap)
            {
                SayTableOutCashed();
                return true;
            }
            break;
        }
        case Data::GameState::Table_OddEven:
        {
            if (aOddEven.myMoney<= tableWinCap)
            {
                SayTableOutCashed();
                return true;
            }
            break;
        }
        case Data::GameState::Table_HighRoll:
        {
            if (aHighRoll.myMoney <= tableWinCap)
            {
                SayTableOutCashed();
                return true;
            }
            break;
        }
        case Data::GameState::Exit_Main:
            break;
        case Data::GameState::Winstreak:
            break;
        default:
        {
            break;
        }
    }
    return false;
}
int SubCalc(const int aValue1, const int aSubValue)
{
    //TODO  const args refactor
    int value = aValue1;
    const int subValue = aSubValue;
    const int subMin = 0;

    value -= subValue;
    if (value < subMin)
    {
        value = subMin;
    }
    return value;
}
void UpdateMoneyTable(const int aBet, Data::GameState& aGameState, const bool aIsWin, Player::Data& aPlayer, TableGuess::Data& aGuess, TableOddEven::Data& aOddEven,  TableHighRoll::Data& aHighRoll)
{
    const int betMoney = aBet;
    const bool isWin = aIsWin;
  
    int tableTotal;

    switch (aGameState)
    {
       case Data::GameState::Table_Guess:
        {
            
            tableTotal = (betMoney * aGuess.myTableMultiplier) + aGuess.myTableBonus;
            if (isWin)
            {
                aPlayer.myMoney += tableTotal;
                aGuess.myMoney = SubCalc(aGuess.myMoney, tableTotal);
                std::cout << "You WON: " << tableTotal << " myMoneys!!" << std::endl;
            }
            else
            {
                aPlayer.myMoney = SubCalc(aPlayer.myMoney, tableTotal);
                aGuess.myMoney += tableTotal;
                std::cout << "You LOST: " << tableTotal << " myMoneys!!" << std::endl;
            }
            break;
        }
        case Data::GameState::Table_OddEven:
        {
            
            ;
            tableTotal = (betMoney * aOddEven.myTableMultiplier % betMoney) + aOddEven.myTableBonus;
            if (isWin)
            {
                aPlayer.myMoney += tableTotal;
                aOddEven.myMoney= SubCalc(aOddEven.myMoney, tableTotal);

                std::cout << "You WON: " << tableTotal << " myMoneys!!" << std::endl;
            }
            else
            {
                aPlayer.myMoney = SubCalc(aPlayer.myMoney, tableTotal);
                aOddEven.myMoney+= tableTotal;
                std::cout << "You LOST: " << tableTotal << " myMoneys!!" << std::endl;
            }
            break;
        }
        case Data::GameState::Table_HighRoll:
        {
            
            tableTotal = (betMoney * aHighRoll.myTableMultiplier) + aHighRoll.myTableBonus;
            if (isWin)
            {
                aPlayer.myMoney += tableTotal;
                aHighRoll.myMoney = SubCalc(aHighRoll.myMoney, tableTotal);
                std::cout << "You WON: " << tableTotal << " myMoneys!!" << std::endl;
            }
            else
            {
                aPlayer.myMoney = SubCalc(aPlayer.myMoney, tableTotal);
                aHighRoll.myMoney += tableTotal;
                
               
                std::cout << "You LOST: " << tableTotal << " myMoneys!!" << std::endl;
            }
            break;
        }
        case Data::GameState::Winstreak:
            break;
        case Data::GameState::Exit_Main:
            break;
        default:
            
            break;
    }
    if (aPlayer.isPoor)
    {
                    std::cout << "You are in debt now wow." << std::endl;
    }
    SayTableMoney(aGameState, aGuess, aOddEven, aHighRoll);
    SayMoneySum(aPlayer);
}

int UpdateBet(Player::Data& player)
{
    int betValue;
    const int minBetValue = 0;
    const int maxBetValue = player.myMoney;
    bool isBetting = true;

    while (isBetting)
    {
        std::cout << "Whats your bet?" << std::endl;
        int input = Casino::InputInt();

        if (minBetValue < input && input <= maxBetValue)
        {
            betValue = input;
            std::cout << "You bet: " << betValue << std::endl;

            if (input == maxBetValue)
            {
                std::cout << "Holy Shcmoly! Thats all your myMoney! " << betValue << std::endl;
            }
            return betValue;
        }
        else
        {
            std::cout << "Nope! You can only bet what you have foo! \n You have: " << player.myMoney << ".\n"
                << "and not below one or negative for queens sake!" << std::endl;
        }
        isBetting = true;
    }
    return 0;
}
void PlayGame(Data::GameState aGameState, Player::Data& aPlayer)
{
    switch (aGameState)
    {
        case Data::GameState::Table_Guess:
        {
            TableGuess::PlayTable(aPlayer);
          
            break;
        }

        case Data::GameState::Table_OddEven:
        {
            TableOddEven::PlayTable(aPlayer);
            break;
        }

        case Data::GameState::Table_HighRoll:
        {
            TableHighRoll::PlayTable(aPlayer);
            break;
        }

        case Data::GameState::Exit_Main:
        case Data::GameState::Winstreak:
        default:
        {
            break;
        }
    }
}
void BeginGameLogic(Data::GameState& aGameState, Player::Data& aPlayer, TableGuess::Data& aGuess, TableOddEven::Data& aOddEven,TableHighRoll::Data& aHighRoll)
{
    PlayGame(aGameState, aPlayer);
    UpdateMoneyTable(UpdateBet(aPlayer), aGameState, aPlayer.isWin, aPlayer, aGuess, aOddEven, aHighRoll);
    UpdateWinStreak(aPlayer.isWin, aPlayer);
}
void EnterTable(Data::GameState aGameState, Player::Data& aPlayer, Casino::Data& aCasino,TableGuess::Data& aGuess, TableOddEven::Data& aOddEven,TableHighRoll::Data& aHighRoll)
{
    aCasino.IsTableActive = true;
    while (aCasino.IsTableActive && AmIPoor(aPlayer) == false && IsTablePoor(aGameState, aGuess, aOddEven, aHighRoll) == false)
    {
        SayTableMenu();
        switch (static_cast<Data::TableMenu>(Casino::InputInt()) )
        {
            case Data::TableMenu::Exit_Table:
            {
                ExitMenu(aCasino);
                break;
            }
            case Data::TableMenu::BeginGame :
            {
                BeginGameLogic(aGameState, aPlayer, aGuess, aOddEven, aHighRoll);
                break;
            }
            case Data::TableMenu::Print_Rules:
            {
                SayRulesTable(aGameState);
                break;
            }
            case Data::TableMenu::Print_Streak:
            {
                PrintWinStreak(aPlayer);
                break;
            }
            default:
            {
                Casino::SayInputError();
                break;
            }
        }
    }
}
void MainMenu(Data::GameState aGameState, Player::Data& aPlayer,Casino::Data& aCasino )
{
    TableGuess::Data guessData;
    TableOddEven::Data oddEvenData;
    TableHighRoll::Data highRollData;
    switch (aGameState)
    {
        case Data::GameState::Exit_Main:
        {
            ExitMenu(aCasino);
            break;
        }
        case Data::GameState::Table_Guess:
        case Data::GameState::Table_OddEven:
        case Data::GameState::Table_HighRoll:
        {
            if (IsTablePoor(aGameState, guessData, oddEvenData, highRollData)==false)
            {
                
                SayGreetingTable(aGameState);
                SayTableTreshold(aGameState, guessData, oddEvenData, highRollData);
                SayMoneySum(aPlayer);
                EnterTable(aGameState, aPlayer, aCasino, guessData, oddEvenData, highRollData);
            }
            break;
        }
        case Data::GameState::Winstreak:
        {
            PrintWinStreak(aPlayer);
            break;
        }
        default:
        {
            Casino::SayInputError();
            break;
        }
    }
}

int main()
{
    Casino::Data casinoData;
    Player::Data player;
    TableGuess::Data tableGuess;
    TableOddEven::Data tableOddEven;
    TableHighRoll::Data tableHighRoll;
    SayEnterCasino();
    casinoData.isMainActive = true;
    while (casinoData.isMainActive && AmIPoor(player) == false)
    {
        SayMainMenuChoices();
        MainMenu(static_cast<Data::GameState>(Casino::InputInt() ), player, casinoData);
    }
    SayByeCasino(player);
};