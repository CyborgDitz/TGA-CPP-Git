#pragma once
#include "Casino.h"


int SubCalc(int aValue1, int aSubValue);
void SayByeCasino( Casino& aCasino);
bool AmIPoor(Casino& aCasino);
bool IsTablePoor( Casino& aCasino);
void SayEnterCasino(Casino& aCasino);
void SayTableOutCashed();
void SayTableTreshold( Casino& aCasino);
void SayTableMoney( Casino& aCasino);
void SayPlayAgain();

void SayMoneySum( Casino& aCasino);
void UpdateMoneyTable( int aBet,  Casino& aCasino);
void UpdateWinStreak(bool aIsWin, Casino& aCasino);
void SayGreetingTable( Casino& aCasino);
void PrintWinStreak( Casino& aCasino);
void ExitMenu(Casino& aCasino);
void BeginGameLogic(Casino& aCasino);
void PlayGame(Casino& aCasino);
void SayTableMenu();
void EnterTableMenu(Casino& aCasino);
void SayMainMenuChoices();
void MainMenu(Casino& aCasino);
