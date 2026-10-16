#pragma once
#include "Casino.h"
#include "Data.h"
#include "Player.h"
#include "TableGuess.h"
#include "TableHighRoll.h"
#include "TableOddEven.h"
#include "TableRoulette.h"


bool IsTablePoor(const Casino::GameState& aGameState, const TableGuess::Data& aGuess, const TableOddEven::Data& aOddEven,
                 const TableHighRoll::Data& aHighRoll, const TableRoulette::Data& aRoulette);
void SayEnterCasino();
void SayTableMenu();
void SayTableOutCashed();
void SayTableTreshold(const Casino::GameState& aGameState, 
  const  TableGuess::Data& aGuess, const TableOddEven::Data& aOddEven, const TableHighRoll::Data& aHighRoll,const TableRoulette::Data& aRoulette);
void SayTableMoney(const Casino::GameState& aGameState,
    const TableGuess::Data& aGuess, const TableOddEven::Data& aOddEven,const TableHighRoll::Data& aHighRoll, const TableRoulette::Data& aRoulette);
void SayGreetingTable(const Casino::GameState& aGameState);

void SayPlayAgain();
void PrintWinStreak(const Player::Data& aPlayer);
void SayByeCasino();
void SayRulesTable(const Casino::GameState& aGameState);
void SayMainMenuChoices();
void SayMoneySum(const Player::Data& aPlayer);

int SubCalc(int aValue1, int aSubValue);


void UpdateMoneyTable( int aBet, const Casino::GameState& aGameState, const bool aIsWin, Player::Data& aPlayer,
                      TableGuess::Data& aGuess, TableOddEven::Data& aOddEven, TableHighRoll::Data& aHighRoll, TableRoulette::Data& aRoulette,TableRoulette::Data::Bets& aBetState);
void UpdateWinStreak(bool aIsWin, Player::Data& aPlayer);
void EnterTableMenu(Casino::GameState aGameState, Player::Data& aPlayer, TableGuess::Data& aGuess, TableOddEven::Data& aOddEven,  TableHighRoll::Data& aHighRoll);
void MainMenu(Casino::GameState aGameState, Player::Data& aPlayer);
void BeginGameLogic(Casino::GameState& aGameState, Player::Data& aPlayer, TableGuess::Data& aGuess, TableOddEven::Data& aOddEven,  TableHighRoll::Data& aHighRoll,TableRoulette::Data& aRoulette);
void PlayGame(Casino::GameState aGameState, Player::Data& aPlayer, TableRoulette::Data& aRoulette);
void ExitMenu(Casino::Data& aCasino);