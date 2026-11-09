#include <iostream>
#include <random>
#include <cstdlib>
#include "Hasardspel.h"
#include "TableGuess.h"
#include "TableOddEven.h"
#include "TableHighRoll.h"
#include "TableRoulette.h"

void SayEnterCasino(Casino& aCasino)
{
    std::cout << "Welcome to the Casino, friend! \n" << std::endl;
    std::cout << "Whats your name?" << std::endl;
    aCasino.GetPlayer().SetName();
    aCasino.GetPlayer().SayName();
    std::cout << " I just transfered this through the casino!" << std::endl;
    std::cout << "What would you like to do, ";
    aCasino.GetPlayer().SayName();
}

void SayTableMenu()
{
    std::cout << "1: Play the game. \t 2: Show Rules.\n" "3: Show Win Streak \t 0: Leave and go back to Main Menu" <<
        std::endl;
};

void SayTableOutCashed()
{
    std::cout << "You have claimed too much of this table, begone!" << std::endl;
}

void SayPlayAgain()
{
    std::cout << "Want to play again? Y or N?" << std::endl;
}

void SayTableTreshold(Casino& aCasino)
{
    switch (aCasino.GetGameState())
    {
    case Casino::GameState::Table_Guess_LowStake :
        {
            aCasino.GetTableGuess().SayGuessTreshHold();
            break;
        }
    case Casino::GameState::Table_Guess_HighStake :
        {
            aCasino.GetTableGuess2().SayGuessTreshHold();
            break;
        }
    case Casino::GameState::Table_OddEven :
        {
            if (aCasino.GetTableOddEven().GetMoney() >= aCasino.GetTableOddEven().GetTreshLoser())
            {
                std::cout << "Try again, regain ";
                aCasino.GetPlayer().SayName();
                std::cout << "your losses!?" << std::endl;
            }
            else if (aCasino.GetTableOddEven().GetMoney() <= aCasino.GetTableOddEven().GetTreshWinner())
            {
                std::cout << "We have a big winner here, why quit when the fire is hot amiright?" << std::endl;
            }
            else
            {
                std::cout << "You should  spend that money here and nowhere else!" << std::endl;
            }
            break;
        }
    case Casino::GameState::Table_HighRoll :
        {
            if (aCasino.GetTableHighRoll().GetMoney() >= aCasino.GetTableHighRoll().GetTreshLoser())
            {
                std::cout << "Try again, regain your losses!?" << std::endl;
            }
            else if (aCasino.GetTableHighRoll().GetMoney() <= aCasino.GetTableHighRoll().GetTreshWinner())
            {
                std::cout << "We have a big winner here, why quit when the fire is hot amiright?" << std::endl;
            }
            else
            {
                std::cout << "You should  spend that money here and nowhere else!" << std::endl;
            }
            break;
        }
    case Casino::GameState::Table_Roulette :
        {
            if (aCasino.GetTableRoulette().GetMoney() >= aCasino.GetTableRoulette().GetTreshLoser())
            {
                std::cout << "Try again, regain your losses!?" << std::endl;
            }
            else if (aCasino.GetTableRoulette().GetMoney() <= aCasino.GetTableRoulette().GetTreshWinner())
            {
                std::cout << "We have a big winner here, why quit when the fire is hot amiright?" << std::endl;
            }
            else
            {
                std::cout << "You should  spend that money here and nowhere else!" << std::endl;
            }
            break;
        }
    case Casino::GameState::Exit_Main :
    case Casino::GameState::Winstreak :
    default :
        {
            break;
        }
    }
}

void SayByeCasino(Casino& aCasino)
{
    SayMoneySum(aCasino);
    std::cout << "Goodbye friend, and  good luck!" << std::endl;
    system("pause");
}

void SayGreetingTable(Casino& aCasino)
{
    switch (aCasino.GetGameState())
    {
    case Casino::GameState::Table_Guess_LowStake :
        {
            std::cout << "This is the best table for the best gambler, the guessing table! \n" << std::endl;
            break;
        }
    case Casino::GameState::Table_OddEven :
        {
            std::cout << "Welcome to the odd or even table!" << std::endl;
            break;
        }
    case Casino::GameState::Table_HighRoll :
        {
            std::cout << "Welcome to the hiiIIiiIIgh Rooool!!" << std::endl;
            break;
        }
    case Casino::GameState::Table_Roulette :
        {
            std::cout << "Welcome to the ROULETTE!" << std::endl;
            break;
        }
    case Casino::GameState::Exit_Main :
    case Casino::GameState::Winstreak :
        {
            break;
        }
    default :
        {
            break;
        }
    }
}


void SayMainMenuChoices()
{
    std::cout << "You can choose between these options \n"
        << "1: Table 1: Guess the Dice Low Stakes\t" << "Table 2. Guess the Dice High Stakes\n"
        << "3:Table 3: Odd or Even\t" << "4: Table 4: Roll Higher\n "
        << "5: Table 5: Roulette\t" << "6: Show Win / Loss Statistics\n "
        << "0: Or leave the casino!\n" << std::endl;
}

void SayMoneySum(Casino& aCasino)
{
    std::cout << "You currently have " << aCasino.GetPlayer().GetMoney() << " dollaridoos! \n";
}

void SayTableMoney(Casino& aCasino)
{
    if (aCasino.GetGameState() == Casino::GameState::Table_Guess_LowStake)
    {
        std::cout << "This table currently have " << aCasino.GetTableGuess().GetMoney() << " dollaridoos! \n";
    }
    else if (aCasino.GetGameState() == Casino::GameState::Table_Guess_HighStake)
    {
        std::cout << "This table currently have " << aCasino.GetTableGuess2().GetMoney() << " dollaridoos! \n";
    }
    else if (aCasino.GetGameState() == Casino::GameState::Table_OddEven)
    {
        std::cout << "This table currently have " << aCasino.GetTableOddEven().GetMoney() << " dollaridoos!\n";
    }
    else if (aCasino.GetGameState() == Casino::GameState::Table_HighRoll)
    {
        std::cout << "This table currently have " << aCasino.GetTableHighRoll().GetMoney() << " dollaridoos! \n";
    }
    else if (aCasino.GetGameState() == Casino::GameState::Table_Roulette)
    {
        std::cout << "This table currently have " << aCasino.GetTableRoulette().GetMoney() << " dollaridoos! \n";
    }
}

void ExitMenu(Casino& aCasino)
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

void PrintWinStreak(Casino& aCasino)
{
    int length = aCasino.GetPlayer().GetStreakMax();


    std::cout << "Your win and loss score is: " << std::endl;
    for (int i = length - 1; i >= 0; i--)
    {
        if (aCasino.GetPlayer().GetWinStreak()[i] == 1)
        {
            std::cout << "W" << std::endl;
        }
        else if (aCasino.GetPlayer().GetWinStreak()[i] == 2)
        {
            std::cout << "L" << std::endl;
        }
        else if ((aCasino.GetPlayer().GetWinStreak()[i]) == 0)
        {
            std::cout << "_" << std::endl;
        }
    }
}

void UpdateWinStreak(Casino& aCasino)
{
    int winValue = 1;
    int lossValue = 2;
    int updateValue;
    if (aCasino.GetPlayer().GetIsWin() == true)
    {
        updateValue = winValue;
    }
    else
    {
        updateValue = lossValue;
    }

    int length = aCasino.GetPlayer().GetStreakMax();
    for (int i = length - 1; i >= 0; i--)
    {
        aCasino.GetPlayer().SetWinStreak(i + 1, aCasino.GetPlayer().GetWinStreak()[i]);
        aCasino.GetPlayer().SetWinStreak(i, updateValue);
    }
    PrintWinStreak(aCasino);
}

int SubCalc(int aValue1, int aSubValue)
{
    //TODO   args refactor
    int value = aValue1;
    int subValue = aSubValue;
    int subMin = 0;

    value -= subValue;
    if (value < subMin)
    {
        value = subMin;
    }
    return value;
}

bool AmIPoor(Casino& aCasino)
{
    if (aCasino.GetPlayer().GetMoney() <= 0 && aCasino.GetPlayer().GetIsPoor() == false)
    {
        std::cout << "Get out of our casino, ";
        aCasino.GetPlayer().SayName();
        aCasino.GetPlayer().SetIsPoor(true);
        return true;
    }
    else if (aCasino.GetPlayer().GetMoney() <= 0)
    {
        return true;
    }
    else
    {
       
        return false;
    }
}

bool IsTablePoor(Casino& aCasino)
{
    //TODO enum refactor
    int tableWinCap = 0;

    switch (aCasino.GetGameState())
    {
    case Casino::GameState::Table_Guess_LowStake :
        {
            if (aCasino.GetTableGuess().GetMoney() <= tableWinCap)
            {
                SayTableOutCashed();
                return true;
            }
            break;
        }
    case Casino::GameState::Table_Guess_HighStake :
        {
            if (aCasino.GetTableGuess2().GetMoney() <= tableWinCap)
            {
                SayTableOutCashed();
                return true;
            }
            break;
        }
    case Casino::GameState::Table_OddEven :
        {
            if (aCasino.GetTableOddEven().GetMoney() <= tableWinCap)
            {
                SayTableOutCashed();
                return true;
            }
            break;
        }
    case Casino::GameState::Table_HighRoll :
        {
            if (aCasino.GetTableHighRoll().GetMoney() <= tableWinCap)
            {
                SayTableOutCashed();
                return true;
            }
            break;
        }
    case Casino::GameState::Table_Roulette :
        {
            if (aCasino.GetTableRoulette().GetMoney() <= tableWinCap)
            {
                SayTableOutCashed();
                return true;
            }
            break;
        }
    case Casino::GameState::Exit_Main :
        {
            break;
        }
    case Casino::GameState::Winstreak :
        {
            break;
        }
    default :
        {
            break;
        }
    }
    return false;
}

void UpdateMoneyTable(const int aBet, Casino& aCasino)
{
    int betMoney = aBet;
    int tableTotal{};
    int tableMult{};
    int tableBonus{};
    switch (aCasino.GetGameState())
    {
    //if case
    case Casino::GameState::Table_Guess_LowStake :
        {
            // movable to inside Class
            tableTotal = (betMoney * aCasino.GetTableGuess().GetTableMultiplier()) + aCasino.GetTableGuess().
                GetTableBonus();
            break;
        }
    case Casino::GameState::Table_Guess_HighStake :
        {
            // movable to inside Class
            tableTotal = (betMoney * aCasino.GetTableGuess2().GetTableMultiplier()) + aCasino.GetTableGuess().
                GetTableBonus();
            break;
        }
    case Casino::GameState::Table_OddEven :
        {
            tableMult = aCasino.GetTableOddEven().GetTableMultiplier();
            tableBonus = aCasino.GetTableOddEven().GetTableBonus();
            tableTotal =  betMoney + (tableMult  % tableBonus);

            break;
        }
    case Casino::GameState::Table_HighRoll :
        {
            tableMult = aCasino.GetTableHighRoll().GetTableMultiplier();
            tableBonus = aCasino.GetTableHighRoll().GetTableBonus();
            tableTotal = (betMoney * (tableMult) + tableBonus);

            break;
        }
    case Casino::GameState::Table_Roulette :
        {
            switch (aCasino.GetTableRoulette().GetBets())
            {
            case TableRoulette::Bet::Invalid :
                {
                    std::cout << "no!" << std::endl;
                    break;
                }
            case TableRoulette::Bet::Straight_Gay :
                {
                    tableTotal = (betMoney * aCasino.GetTableRoulette().GetStraightGayMult());

                    break;
                }

            case TableRoulette::Bet::Red_Black :
                {
                    tableTotal = (betMoney * aCasino.GetTableRoulette().GetRedBlackMult());

                    break;
                }
            case TableRoulette::Bet::Odd_Even :
                {
                    tableTotal = (betMoney * aCasino.GetTableRoulette().GetOddEvenMult());

                    break;
                }
            case TableRoulette::Bet::Column :
                {
                    tableTotal = (betMoney * aCasino.GetTableRoulette().GetColumnMult());

                    break;
                }
            }
        case Casino::GameState::Exit_Main :
            {
                break;
            }
        case Casino::GameState::Winstreak :
            {
                break;
            }
        default :
            {
                break;
            }
        }
    }
    //function
    if (aCasino.GetPlayer().GetIsWin() == true)
    {
        aCasino.AddPlayerMoney(tableTotal);
        aCasino.SubTableMoney(tableTotal);
        std::cout << "You WON: " << tableTotal << " moneys!!" << std::endl;
    }
    else
    {
        aCasino.SubPlayerMoney(tableTotal);
        aCasino.AddTableMoney(tableTotal);
        std::cout << "You LOST: " << tableTotal << " moneys!!" << std::endl;
    }
    if (aCasino.GetPlayer().GetIsPoor() == true)
    {
        std::cout << "You are in debt now wow." << std::endl;
    }
    SayTableMoney(aCasino);
    SayMoneySum(aCasino);
}


int UpdateBet(Casino& aCasino)
{
    int betValue; 
   Casino::GameState state =  aCasino.GetGameState();
   int minBetValue = 1;
   int maxBetValue = aCasino.GetPlayer().GetMoney();
    
    if (state == Casino::GameState::Table_Guess_LowStake)
    {
        minBetValue = aCasino.GetTableGuess().GetBetMin();
        maxBetValue =aCasino.GetTableGuess().GetBetMax();
    }
    else if (state == Casino::GameState::Table_Guess_HighStake)
    {
        minBetValue = aCasino.GetTableGuess2().GetBetMin();
        maxBetValue =aCasino.GetTableGuess2().GetBetMax();
    }
    
    bool isBetting = true;

    while (isBetting)
    {
        std::cout << "Whats your bet " << aCasino.GetPlayer().GetName() << "?" << std::endl;
        std::cout << "The minimum BETS are " << minBetValue << " and " << maxBetValue << std::endl;
        int input = aCasino.InputInt();

        if (minBetValue <= input && input <= maxBetValue)
        {
            betValue = input;
            aCasino.GetPlayer().SayName();
            std::cout << " bet: " << betValue << std::endl;

            if (input == maxBetValue)
            {
                std::cout << "Holy Shcmoly! Thats all your myMoney ";
                aCasino.GetPlayer().SayName();
                std::cout << "!" << std::endl;
            }

            return betValue;
        }
        else
        {
            std::cout << "Nope! You can only bet what you have foo! \n";
            aCasino.GetPlayer().SayName();
            std::cout << " have: " << aCasino.GetPlayer().GetMoney() <<
                ".\n"
                << "and not below the minBet, maxBet, OR negative for queens sake!" << std::endl;
        }
        isBetting = true;
    }
    return betValue = 1;
}

void PlayGame(Casino& aCasino)
{

        switch (aCasino.GetGameState())
        {
        case Casino::GameState::Table_Guess_LowStake :
            {
               
                aCasino.PlayTableGuess(aCasino);
                break;
            }
        case Casino::GameState::Table_Guess_HighStake :
            {
                
                aCasino.PlayTableGuess(aCasino);
                break;
            }
        case Casino::GameState::Table_OddEven :
            {
                aCasino.PlayTableOddEven(aCasino);
                
                break;
            }

        case Casino::GameState::Table_HighRoll :
            {
                aCasino.PlayTableHighRoll(aCasino);
                
                break;
            }
        case Casino::GameState::Table_Roulette :
            {
                aCasino.RouletteBet(aCasino);
                break;
            }

        case Casino::GameState::Exit_Main :
        case Casino::GameState::Winstreak :
        default :
            {
                break;
            }
        }
    
}

void BeginGameLogic(Casino& aCasino)
{
    int bet = UpdateBet(aCasino);
    PlayGame(aCasino);
    UpdateMoneyTable(bet, aCasino);
    UpdateWinStreak(aCasino);
}

void EnterTableMenu(Casino& aCasino)
{
    aCasino.IsTableActive = true;
    while (aCasino.IsTableActive && AmIPoor(aCasino) == false && IsTablePoor(aCasino) == false)
    {
        SayTableMenu();
        Casino::TableMenu table = static_cast<Casino::TableMenu>(aCasino.InputInt());
        switch (table)
        {
        case Casino::TableMenu::Exit_Table :
            {
                ExitMenu(aCasino);
                break;
            }
        case Casino::TableMenu::BeginGame :
            {
                BeginGameLogic(aCasino);
                break;
            }
        case Casino::TableMenu::Print_Rule :
            {
                aCasino.SayRulesTable();
                break;
            }
        case Casino::TableMenu::Print_Streak :
            {
                PrintWinStreak(aCasino);
                break;
            }
        default :
            {
                aCasino.SayInputError();
                break;
            }
        }
    }
}

void MainMenu(Casino& aCasino)
{
    switch (aCasino.GetGameState())
    {
    case Casino::GameState::Exit_Main :
        {
            ExitMenu(aCasino);
            break;
        }
    case Casino::GameState::Table_Guess_LowStake :
    case Casino::GameState::Table_Guess_HighStake :
    case Casino::GameState::Table_OddEven :
    case Casino::GameState::Table_HighRoll :
    case Casino::GameState::Table_Roulette :
        {
            {
                if (IsTablePoor(aCasino) == false)
                {
                    aCasino.SayRulesTable();
                    SayGreetingTable(aCasino);
                    SayTableTreshold(aCasino);
                    SayMoneySum(aCasino);
                }
            }
            EnterTableMenu(aCasino);
            break;
        }
    case Casino::GameState::Winstreak :
        {
            PrintWinStreak(aCasino);
            break;
        }
    default :
        {
            aCasino.SayInputError();
            break;
        }
    }
}

int main()
{
    Casino casino;
    SayEnterCasino(casino);


    casino.isMainActive = true;
    while (casino.isMainActive && AmIPoor(casino) == false)
    {
        SayMainMenuChoices();
        casino.SetGameState(static_cast<Casino::GameState>(casino.InputInt()));
        MainMenu(casino);
    }
    SayByeCasino(casino);
};

