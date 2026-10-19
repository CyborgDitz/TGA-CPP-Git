#pragma once
#include "Player.h"
#include "TableGuess.h"
#include "TableHighRoll.h"
#include "TableOddEven.h"
#include "TableRoulette.h"

class Casino
{
public:
    enum class OddCoin
    {
        No_Coin,
        Odd,
        Even
    };

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
        Table_Guess_LowStakes,
        Table_Guess_HighStakes,
        Table_OddEven,
        Table_HighRoll,
        Table_Roulette,
        Winstreak
    };
    Player& GetPlayer() { return player; }
    TableGuess& GetTableGuess() { return tableGuess; }
    TableGuess& GetTableGuess2() { return tableGuess2; }
    TableOddEven& GetTableOddEven() { return tableOddEven; }
    TableHighRoll& GetTableHighRoll() { return tableHighRoll; }
    TableRoulette& GetTableRoulette() { return tableRoulette; }
    
    TableMenu& GetTableMenu()  { return tableMenu; }
    OddCoin& GetOddCoin() { return oddCoin; }
    GameState& GetGameState() { return gameState; }
    
    void SayInputError();
    int InputInt();
    void SayAskReadyToRoll(Casino& aCasino);
    int RollDie();
    int RollRoulette();
    void SayWin(Casino& aCasino);
    void SayLose(Casino& aCasino);
    void PlayColumn(Casino& aCasino);
    void PlayRouColorOrOdd(Casino& aCasino, const TableRoulette::Color& aColor);
    void RouletteBet(Casino& aCasino);
    void PlayStraight(Casino& aCasino);
    void SayRulesTable(Casino& aCasino);
    void PlayTableGuess(Casino& aCasino, TableGuess& aTableGuess);
    void PlayTableOddEven(Casino& aCasino);
    void PlayTableHighRoll(Casino& aCasino);
    
    
   void CalcRouletteColorAndOdd(Casino& aCasino);

  
    void SetOddCoin(const OddCoin& aOddCoin) { oddCoin = aOddCoin; }
    void SetTableMenu(const TableMenu& aTableMenu) { tableMenu = aTableMenu; }
    void SetGameState(const GameState& aGameState) { gameState = aGameState; }
    void AddPlayerMoney (const int aMoney) { player.AddMoney(aMoney); }
    void SubPlayerMoney (const int aMoney) { player.SubMoney(aMoney); }
    void AddTableMoney (const int aMoney);
    void SubTableMoney(int aMoney);
    bool isMainActive = false;
    bool IsTableActive = false;
    OddCoin CalcOddEven(Casino& aCasino);

private:
    OddCoin oddCoin{};
    TableMenu tableMenu{};
    GameState gameState{};
    Player player;
    TableGuess tableGuess{2,16};
    TableGuess tableGuess2{8,32};
    TableOddEven tableOddEven;
    TableHighRoll tableHighRoll;
    TableRoulette tableRoulette;
};
