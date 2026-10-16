#pragma once
#include "Casino.h"
#include "Data.h"
#include "Player.h"
#include "TableGuess.h"
#include "TableHighRoll.h"
#include "TableOddEven.h"

void SayTableMenu();
bool IsTablePoor(const Data::GameState& aGameState,  const TableGuess::Data& aGuess, const TableOddEven::Data& aOddEven, const TableHighRoll::Data& aHighRoll);
void SayEnterCasino();
void SayTableMenu();
void SayTableOutCashed();
void SayTableTreshold(const Data::GameState& aGameState, 
    TableGuess::Data& aGuess, TableOddEven::Data& aOddEven, TableHighRoll::Data& aHighRoll);
void SayGreetingTable(Data::GameState& aGameState);

void SayPlayAgain();
void PrintWinStreak(const Player::Data& aPlayer);
void SayByeCasino();
void SayRulesTable(Data::GameState& aGameState);
void SayMainMenuChoices();
void SayMoneySum(const Player::Data& aPlayer);
void SayTableMoney(const Data::GameState& aGameState,
TableGuess::Data& aGuess, TableOddEven::Data& aOddEven, TableHighRoll::Data& aHighRoll);

int SubCalc(int aValue1, int aSubValue);


void UpdateMoneyTable(int aBet, Data::GameState& aGameState, bool aIsWin, Player::Data& aPlayer,
    TableGuess::Data& aGuess, TableOddEven::Data& aOddEven,  TableHighRoll::Data& aHighRoll);
void UpdateWinStreak(bool aIsWin, Player::Data& aPlayer);
void EnterTable(Data::GameState aGameState, Player::Data& aPlayer, TableGuess::Data& aGuess, TableOddEven::Data& aOddEven,  TableHighRoll::Data& aHighRoll);
void MainMenu(Data::GameState aGameState, Player::Data& aPlayer);
void BeginGameLogic(Data::GameState& aGameState, Player::Data& aPlayer, TableGuess::Data& aGuess, TableOddEven::Data& aOddEven,  TableHighRoll::Data& aHighRoll);
void PlayGame(Data::GameState aGameState, Player::Data& aPlayer);
void ExitMenu(Casino::Data& aCasino);