#include <iostream>
#include <random>
#include <cstdlib>
#include "Hasardspel.h"
#include "TableGuess.h"
#include "TableOddEven.h"
#include "TableHighRoll.h"
#include "TableRoulette.h"

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
void SayTableTreshold(const Casino::GameState& aGameState,
                      const TableGuess::Data& aGuess,const TableOddEven::Data& aOddEven,const TableHighRoll::Data& aHighRoll, const TableRoulette::Data& aRoulette)
{
    // debug SayTableSpoils(aGameState);
    // optimizable cases for multiple usage of code (bools), use for loop if true with enum
    switch (aGameState)
    {
        case Casino::GameState::Table_Guess:
        {
            if (aGuess.myMoney >= aGuess.myTreshBig)
            {
                std::cout << "We have a big winner here, why quit when the fire is hot amiright?" << std::endl;
            }
            else if (aGuess.myMoney <= aGuess.myTreshSmall)
            {
                std::cout << "Try again, regain your losses!?" << std::endl;
            }
            else
            {
                std::cout << "You should  spend that money here and nowhere else!" << std::endl;
            }
            break;
        }
        case Casino::GameState::Table_OddEven:
        {
            if (aOddEven.myMoney >= aOddEven.myTreshBig)
            {
                std::cout << "We have a big winner here, why quit when the fire is hot amiright?" << std::endl;
            }
            else if (aOddEven.myMoney <= aOddEven.myTreshSmall)
            {
                std::cout << "Try again, regain your losses!?" << std::endl;
            }
            else
            {
                std::cout << "You should  spend that money here and nowhere else!" << std::endl;
            }
            break;
        }
        case Casino::GameState::Table_HighRoll:
        {
            if (aHighRoll.myMoney >= aHighRoll.myTreshBig)
            {
                std::cout << "We have a big winner here, why quit when the fire is hot amiright?" << std::endl;
            }
            else if (aHighRoll.myMoney <= aHighRoll.myTreshBig)
            {
                std::cout << "Try again, regain your losses!?" << std::endl;
            }
            else
            {
                std::cout << "You should  spend that money here and nowhere else!" << std::endl;
            }
            break;
        }
        case Casino::GameState::Table_Roulette:
        {
            if (aRoulette.myMoney >= aRoulette.myTreshBig)
            {
                std::cout << "We have a big winner here, why quit when the fire is hot amiright?" << std::endl;
            }
            else if (aRoulette.myMoney <= aRoulette.myTreshSmall)
            {
                std::cout << "Try again, regain your losses!?" << std::endl;
            }
            else
            {
                std::cout << "You should  spend that money here and nowhere else!" << std::endl;
            }
            break;
        }
        case Casino::GameState::Exit_Main:
        case Casino::GameState::Winstreak:
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
void SayGreetingTable(const Casino::GameState& aGameState)
{
    switch (aGameState)
    {
        case Casino::GameState::Table_OddEven:
        {
            std::cout << "This is the best table for the best gambler, the guessing table! \n"
                << "If you guess the sum of my 2 dice then you win! \n" << std::endl;
            break;
        }
        case Casino::GameState::Table_Guess:
        {
            std::cout << "Welcome to the odd or even table!" << std::endl;
            break;
        }
        case Casino::GameState::Table_HighRoll:
        {
            
            break;
        }
        case Casino::GameState::Table_Roulette:
        {
            std::cout << "Welcome to the ROULETTE!" << std::endl;
            break;
        }
        case Casino::GameState::Exit_Main:
        case Casino::GameState::Winstreak:
        {
            break;
        }
        default:
        {
            break;
        }
    }
}
void SayRulesTable(const Casino::GameState& aGameState)
{
    switch (aGameState)
    {
        case Casino::GameState::Table_Guess:
        {
            std::cout << "The table is open! So give me one between 2 and 12! Lets gamble!" << std::endl;
            break;
        }
        case Casino::GameState::Table_OddEven:
        {
            std::cout << "The table is open! So guess if its 1: Odd, 2: even! 50 50!" << std::endl;
            break;
        }
        case Casino::GameState::Table_HighRoll:
        {
            std::cout << "Just roll higher than me!" << std::endl;
            break;
        }
        case Casino::GameState::Table_Roulette:
        {
            std::cout << "There are four bet types: \n"
                         << "1. Straight, guess a the number the ball lands on, between 0 and 36\n" <<
                             "2. Red or Black, guess the color of the number the ball lands on! However, the 0 is green and you cant guess that. \n" <<
                                 "3. Odd or Even, guess if the number is odd or even! However, the 0 doesnt count as either!" <<
                                     "4. Column Bet, there are three columns where the ball can land on.\n " <<
                                     "Left, middle, or right. The numbers are shown here (insert picture)" << std::endl;
                                 
            break;
        }
        case Casino::GameState::Exit_Main:
        case Casino::GameState::Winstreak:
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
        << "3: Table 3: Roll Higher \t 4: Table 4: Roulette\n"
        << "5: Show Win / Loss Statistics \t 0: Or leave the casino!\n" << std::endl;
}
void SayMoneySum(const Player::Data& aPlayer)
{
    std::cout << "You currently have " << aPlayer.myMoney << " dollaridoos! \n";
}
void SayTableMoney(const Casino::GameState& aGameState, const TableGuess::Data& aGuess, const TableOddEven::Data& aOddEven, 
    const TableHighRoll::Data& aHighRoll,const TableRoulette::Data& aRoulette)
{
    if (aGameState == Casino::GameState::Table_Guess)
    {
        std::cout << "This table currently have " << aGuess.myMoney << " dollaridoos! \n";
    }
    else if (aGameState == Casino::GameState::Table_OddEven)
    {
        std::cout << "This table currently have " << aOddEven.myMoney << " dollaridoos!\n";
    }
    else if (aGameState == Casino::GameState::Table_HighRoll)
    {
        std::cout << "This table currently have " << aHighRoll.myMoney << " dollaridoos! \n";
    }
    else if (aGameState == Casino::GameState::Table_Roulette)
    {
        std::cout << "This table currently have " << aRoulette.myMoney << " dollaridoos! \n";
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
    const int length = aPlayer.streakArrayMax;
    
    
    std::cout << "Your win and loss score is: " << std::endl;
    for (int i = length-1; i >= 0; i--)
    {
        if (static_cast<int>(aPlayer.winStreak[i]) == 1)
        {
            std::cout << "W" << std::endl;
        }
        else if (static_cast<int>(aPlayer.winStreak[i]) == 2)
        {
            std::cout << "L" << std::endl;
        }
        if (static_cast<int>(aPlayer.winStreak[i]) == 0)
        {
            std::cout << "_" << std::endl;
        }
        
    }
}
void UpdateWinStreak(bool aIsWin, Player::Data& aPlayer)
{
    const int winValue = 1;
    const int lossValue = 2;
    int updateValue;
    if (aIsWin == true)
    {
        updateValue = winValue;
    }
    else
    {
       updateValue = lossValue ;
    }

    const int length = aPlayer.streakArrayMax;
    for (int i = length-1; i >= 0; i--)
    {
        aPlayer.winStreak[i + 1] = aPlayer.winStreak[i];
        aPlayer.winStreak[i] = updateValue;
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
bool IsTablePoor(const Casino::GameState& aGameState, const TableGuess::Data& aGuess, const TableOddEven::Data& aOddEven,
                 const TableHighRoll::Data& aHighRoll, const TableRoulette::Data& aRoulette)
{
    //TODO enum refactor
    const int tableWinCap = 0;

    switch (aGameState)
    {
        case Casino::GameState::Table_Guess:
        {
            if (aGuess.myMoney <= tableWinCap)
            {
                SayTableOutCashed();
                return true;
            }
            break;
        }
        case Casino::GameState::Table_OddEven:
        {
            if (aOddEven.myMoney <= tableWinCap)
            {
                SayTableOutCashed();
                return true;
            }
            break;
        }
        case Casino::GameState::Table_HighRoll:
        {
            if (aHighRoll.myMoney <= tableWinCap)
            {
                SayTableOutCashed();
                return true;
            }
            break;
        }
        case Casino::GameState::Table_Roulette:
        {
            if (aRoulette.myMoney <= tableWinCap)
            {
                SayTableOutCashed();
                return true;
            }
            break;
        }
        case Casino::GameState::Exit_Main:
            break;
        case Casino::GameState::Winstreak:
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
void UpdateMoneyTable(int aBet, const Casino::GameState& aGameState, const bool aIsWin, Player::Data& aPlayer,
                      TableGuess::Data& aGuess, TableOddEven::Data& aOddEven, TableHighRoll::Data& aHighRoll, TableRoulette::Data& aRoulette, TableRoulette::Data::Bets& aBetState)
{
    const int betMoney = aBet;
    const bool isWin = aIsWin;

    int tableTotal;

    switch (aGameState)
    {
        case Casino::GameState::Table_Guess:
        {
            tableTotal = (betMoney * aGuess.myTableMultiplier) + aGuess.myTableBonus;
            if (isWin)
            {
                aPlayer.myMoney += tableTotal;
                aGuess.myMoney = SubCalc(aGuess.myMoney, tableTotal);
                std::cout << "You WON: " << tableTotal << " moneys!!" << std::endl;
            }
            else
            {
                aPlayer.myMoney = SubCalc(aPlayer.myMoney, tableTotal);
                aGuess.myMoney += tableTotal;
                std::cout << "You LOST: " << tableTotal << " moneys!!" << std::endl;
            }
            break;
        }
        case Casino::GameState::Table_OddEven:
        {
            tableTotal = (betMoney * aOddEven.myTableMultiplier % betMoney) + aOddEven.myTableBonus;
            if (isWin)
            {
                aPlayer.myMoney += tableTotal;
                aOddEven.myMoney = SubCalc(aOddEven.myMoney, tableTotal);

                std::cout << "You WON: " << tableTotal << " moneys!!" << std::endl;
            }
            else
            {
                aPlayer.myMoney = SubCalc(aPlayer.myMoney, tableTotal);
                aOddEven.myMoney += tableTotal;
                std::cout << "You LOST: " << tableTotal << " myneys!!" << std::endl;
            }
            break;
        }
        case Casino::GameState::Table_HighRoll:
        {

            tableTotal = (betMoney * aHighRoll.myTableMultiplier) + aHighRoll.myTableBonus;
            if (isWin)
            {
                aPlayer.myMoney += tableTotal;
                aHighRoll.myMoney = SubCalc(aHighRoll.myMoney, tableTotal);
                std::cout << "You WON: " << tableTotal << " moneys!!" << std::endl;
            }
            else
            {
                aPlayer.myMoney = SubCalc(aPlayer.myMoney, tableTotal);
                aHighRoll.myMoney += tableTotal;


                std::cout << "You LOST: " << tableTotal << " moneys!!" << std::endl;
            }
            break;
        }
        case Casino::GameState::Table_Roulette:
        {
            
        
           switch (aBetState)
           {
               case TableRoulette::Data::Bets::Invalid:
               {
                   std::cout << "no!" << std::endl;
                   break;
               }
               case TableRoulette::Data::Bets::Straight_Gay:
               {
                   tableTotal = (betMoney * aRoulette.myStraighGayMult);
                   if (isWin)
                   {
                       aPlayer.myMoney += tableTotal;
                       aRoulette.myMoney = SubCalc(aRoulette.myMoney, tableTotal);
                       std::cout << "You WON: " << tableTotal << " moneys!!" << std::endl;
                   }
                   else
                   {
                       aPlayer.myMoney = SubCalc(aPlayer.myMoney, tableTotal);
                       aRoulette.myMoney += tableTotal;
                
                       std::cout << "You LOST: " << tableTotal << " moneys!!" << std::endl;
                   }
                   break;
               }
             
               case TableRoulette::Data::Bets::Red_Black:
               {
                   tableTotal = (betMoney * aRoulette.myRedBlackMult);
                   if (isWin)
                   {
                       aPlayer.myMoney += tableTotal;
                       aRoulette.myMoney = SubCalc(aRoulette.myMoney, tableTotal);
                       std::cout << "You WON: " << tableTotal << " moneys!!" << std::endl;
                   }
                   else
                   {
                       aPlayer.myMoney = SubCalc(aPlayer.myMoney, tableTotal);
                       aRoulette.myMoney += tableTotal;
                
                       std::cout << "You LOST: " << tableTotal << " moneys!!" << std::endl;
                   }
                   break;
               }
               case TableRoulette::Data::Bets::Odd_Even:
               {
                   tableTotal = (betMoney * aRoulette.myOddEvenMult);
                   if (isWin)
                   {
                       aPlayer.myMoney += tableTotal;
                       aRoulette.myMoney = SubCalc(aRoulette.myMoney, tableTotal);
                       std::cout << "You WON: " << tableTotal << " moneys!!" << std::endl;
                   }
                   else
                   {
                       aPlayer.myMoney = SubCalc(aPlayer.myMoney, tableTotal);
                       aRoulette.myMoney += tableTotal;
                
                       std::cout << "You LOST: " << tableTotal << " moneys!!" << std::endl;
                   }
                   break;
               }
               case TableRoulette::Data::Bets::Column:
               {
                   tableTotal = (betMoney * aRoulette.myColumnMult);
                   if (isWin)
                   {
                       aPlayer.myMoney += tableTotal;
                       aRoulette.myMoney = SubCalc(aRoulette.myMoney, tableTotal);
                       std::cout << "You WON: " << tableTotal << " moneys!!" << std::endl;
                   }
                   else
                   {
                       aPlayer.myMoney = SubCalc(aPlayer.myMoney, tableTotal);
                       aRoulette.myMoney += tableTotal;
                
                       std::cout << "You LOST: " << tableTotal << " moneys!!" << std::endl;
                   }
                   break;
               }

           }
            
            break;
        }
        case Casino::GameState::Winstreak:
        {
            break;
        }
        case Casino::GameState::Exit_Main:
        {
            break;
        }
        default:
        {
            break;
        }
    }
    if (aPlayer.isPoor)
    {
        std::cout << "You are in debt now wow." << std::endl;
    }
    SayTableMoney(aGameState, aGuess, aOddEven, aHighRoll, aRoulette);
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
void PlayGame(Casino::GameState aGameState, Player::Data& aPlayer, TableRoulette::Data& aRoulette, TableRoulette::Data::Bets& aBetState)
{
    switch (aGameState)
    {
        case Casino::GameState::Table_Guess:
        {
            TableGuess::PlayTable(aGameState, aPlayer);

            break;
        }

        case Casino::GameState::Table_OddEven:
        {
            TableOddEven::PlayTable(aGameState, aPlayer);
            break;
        }

        case Casino::GameState::Table_HighRoll:
        {
            TableHighRoll::PlayTable(aPlayer);
            break;
        }
        case Casino::GameState::Table_Roulette:
        {
            TableRoulette::PlayTable(aPlayer, aRoulette, aBetState);
            break;
        }

        case Casino::GameState::Exit_Main:
        case Casino::GameState::Winstreak:
        default:
        {
            break;
        }
        
    }
}
void BeginGameLogic(Casino::GameState& aGameState, Player::Data& aPlayer, TableGuess::Data& aGuess, TableOddEven::Data& aOddEven,
                    TableHighRoll::Data& aHighRoll, TableRoulette::Data& aRoulette)
{
    const int bet = UpdateBet(aPlayer);
    TableRoulette::Data::Bets  betState = {};
    PlayGame(aGameState, aPlayer, aRoulette,  betState);
    UpdateMoneyTable(bet, aGameState, aPlayer.isWin, aPlayer, aGuess, aOddEven, aHighRoll,aRoulette, betState);
    UpdateWinStreak(aPlayer.isWin, aPlayer);
}
void EnterTableMenu(Casino::GameState aGameState, Player::Data& aPlayer, Casino::Data& aCasino, TableGuess::Data& aGuess,
                TableOddEven::Data& aOddEven, TableHighRoll::Data& aHighRoll, TableRoulette::Data& aRoulette)
{
    aCasino.IsTableActive = true;
    while (aCasino.IsTableActive && AmIPoor(aPlayer) == false && IsTablePoor(aGameState, aGuess, aOddEven, aHighRoll, aRoulette) == false)
    {
        SayTableMenu();
        switch (static_cast<Casino::TableMenu>(Casino::InputInt()))
        {
            case Casino::TableMenu::Exit_Table:
            {
                ExitMenu(aCasino);
                break;
            }
            case Casino::TableMenu::BeginGame:
            {
                
                BeginGameLogic(aGameState, aPlayer, aGuess, aOddEven, aHighRoll, aRoulette);
                break;
            }
            case Casino::TableMenu::Print_Rules:
            {
                SayRulesTable(aGameState);
                break;
            }
            case Casino::TableMenu::Print_Streak:
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
void MainMenu(Casino::GameState aGameState, Player::Data& aPlayer, Casino::Data& aCasino)
{
    TableGuess::Data guess;
    TableOddEven::Data oddEven;
    TableHighRoll::Data highRoll;
    TableRoulette::Data roulette;
    switch (aGameState)
    {
        case Casino::GameState::Exit_Main:
        {
            ExitMenu(aCasino);
            break;
        }
        case Casino::GameState::Table_Guess:
        case Casino::GameState::Table_OddEven:
        case Casino::GameState::Table_HighRoll:
        case Casino::GameState::Table_Roulette:
        {
            {
                if (IsTablePoor(aGameState, guess, oddEven, highRoll, roulette) == false)
                {
                    SayGreetingTable(aGameState);
                    SayTableTreshold(aGameState, guess, oddEven, highRoll, roulette);
                    SayMoneySum(aPlayer);
                }
            }
            EnterTableMenu(aGameState, aPlayer, aCasino, guess, oddEven, highRoll, roulette);
            break;
        }
        case Casino::GameState::Winstreak:
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
    SayEnterCasino();
    casinoData.isMainActive = true;
    while (casinoData.isMainActive && AmIPoor(player) == false)
    {
        SayMainMenuChoices();
        MainMenu(static_cast<Casino::GameState>(Casino::InputInt()), player, casinoData);
    }
    SayByeCasino(player);
};
