#pragma once
#include <iostream>
void SayMoneySum(int aMoneyValue)
{
	int moneySum = aMoneyValue;
	int moneyHigh = 5000;
	std::cout << "You currently have " << moneySum << " dollaridoos! \n";
	if (moneySum >= moneyHigh)
		std::cout <<"! Thats a lot of money!!! \n";
}

void SayEnterCasino()
{
	std::cout << "Welcome to the Casino, friend! \n" << std::endl;
	std::cout<< "What would you like to do? \n" << std::endl;
}


void SayGreetingGuessGame()
{
	std::cout << "This is the best table for the best gambler, the guessing table! \n"
		<< "If you guess the sum of my 2 dice then you win! \n" << std::endl;
}
void SayHiOddEven()
{
	std::cout << "Welcome to the odd or even table!" << std::endl;
}
void SayMainMenu()
{
	std::cout << "You can choose between these options \n" <<
		"1: Table 1: Guess the Dice \t 2: Table 2: Odd or Even \t 0: Or leave the casino!\n"
		<< std::endl;
}
void SayHiGuessSum()
{
	std::cout << "Welcome to the guess the sum table" << std::endl;
}
void SayByeCasino(int aMoneySum)
{
	int playerMoney = aMoneySum;
	SayMoneySum(playerMoney);
	std::cout << "Goodbye friend, and  good luck!" << std::endl;
	system("pause");
}
void SayInputError()
{
	std::cout << "wrong input!" << std::endl;
}

void SayWin()
{
	std::cout << "You guessed correct!" << std::endl;
	
}
void SayLose()
{
	std::cout << "Thats wrong, you unlucky fool! \n" << std::endl;
}
void SayRulesSum()
{
	std::cout << "The table is open! So give me one between 2 and 12! Lets gamble!" << std::endl;
}
void SayRulesOddEven()
{
	std::cout << "The table is open! So guess if its 1: Odd, 2: even! 50 50!" << std::endl;
}
void SayPlayAgain()
{
	std::cout << "Want to play again? Y or N?" << std::endl;
}