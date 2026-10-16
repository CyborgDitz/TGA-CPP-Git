#include <iostream>
#include <random>
#include <cstdlib>
#include "PrintCasino.h"

bool isGlobalMainActive;
bool isGlobalTableActive;
int globalPlayerMoney = 99999;
int globalTableMoney1 = 100;
int globalTableMoney2 = 100;
int globalTableMoney3 = 50;
int globalTresholdBig = 200;
int globalTresholdSmall = 50;
const int globalRatioTrackMax = 5;
char globalWinRatio[globalRatioTrackMax] = { '0','0','0','0','0' };

bool IsTablePoor(int aTableState);
int RollDie();
int SubCalc(int aValue1, int aSubValue);
int InputInt();
void SayTableOutCashed();
void SayEnterCasino();
void SayTableMenu();
void SayPlayAgain();
void PrintWinStreak();
void SayByeCasino();
void SayRulesTable(int aTableState);
void SayMainMenuChoices();
void SayWin();
void SayLose();
void SayMoneySum();
void SayTableMoney(int aTableState);
void SayInputError();
void UpdateWinStreak(bool aIsWin);
void EnterTable(int aTableState);
void GameState(int aTableState);
void BeginGameLogic(int aTableState);
void Exit();

void SayEnterCasino()
{
	std::cout << "Welcome to the Casino, friend! \n" << std::endl;
	std::cout << "What would you like to do? \n" << std::endl;
}
void SayTableMenu()
{
	std::cout << "1: Play the game. \t 2: Show Rules.\n" "3: Show Win Streak \t 0: Leave and go back to Main Menu" << std::endl;
};
void SayGreetingTable(int aTableState);
void SayPlayAgain()
{
	std::cout << "Want to play again? Y or N?" << std::endl;
}
void SayTableTreshold(int aTableState)
{
	// debug SayTableSpoils(aTableState);
	switch (aTableState)
	{
		case 1:
		{
			if (globalTableMoney1 > globalTresholdBig)
			{
				std::cout << "We have a big winner here, why quit when the fire is hot amiright?" << std::endl;
			}
			else if (globalTableMoney1 < globalTresholdSmall)
			{
				std::cout << "Try again, regain your losses!?" << std::endl;
			}
			else
			{
				std::cout << "You should  spend that money here and nowhere else!" << std::endl;
			}
			break;
		}
		case 2:
		{
			if (globalTableMoney2 > globalTresholdBig)
			{
				std::cout << "We have a big winner here, why quit when the fire is hot amiright?" << std::endl;
			}
			else if (globalTableMoney2 < globalTresholdSmall)
			{
				std::cout << "Try again, regain your losses!?" << std::endl;
			}
			else
			{
				std::cout << "You should  spend that money here and nowhere else!" << std::endl;
			}
			break;
		}
		case 3:
		{
			if (globalTableMoney3 > globalTresholdBig)
			{
				std::cout << "We have a big winner here, why quit when the fire is hot amiright?" << std::endl;
			}
			else if (globalTableMoney3 < globalTresholdSmall)
			{
				std::cout << "Try again, regain your losses!?" << std::endl;
			}
			else
			{
				std::cout << "You should  spend that money here and nowhere else!" << std::endl;
			}
			break;
		}
		default:
		{
			break;
		}
	}
}
void SayAskReadyToRoll()
{
	std::cout << "Ready to roll? Press any key to GO!" << std::endl;
}
void SayByeCasino()
{
	SayMoneySum();
	std::cout << "Goodbye friend, and  good luck!" << std::endl;
	system("pause");
}
void SayRulesTable(int aTableState)
{
	int tableState = aTableState;

	switch (tableState)
	{
		case 1:
		{
			std::cout << "The table is open! So give me one between 2 and 12! Lets gamble!" << std::endl;
			break;
		}
		case 2:
		{
			std::cout << "The table is open! So guess if its 1: Odd, 2: even! 50 50!" << std::endl;
			break;
		}
		case 3:
		{
			std::cout << "Just roll higher than me!" << std::endl;
			break;
		}
		default:
		{
			SayInputError();
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
void SayWin()
{
	std::cout << "You win!" << std::endl;
}
void SayLose()
{
	std::cout << "Thats your loss, you unlucky fool! \n" << std::endl;
}
void SayGreetingTable(int aTableState)
{
	switch (aTableState)
	{
		case 1:
		{
			std::cout << "This is the best table for the best gambler, the guessing table! \n"
				<< "If you guess the sum of my 2 dice then you win! \n" << std::endl;
			break;
		}
		case 2:
		{
			std::cout << "Welcome to the odd or even table!" << std::endl;
			break;
		}
		case 3:
		{
			std::cout << "Welcome to the simple Die Roll vs Den!" << std::endl;
			break;
		}
		default:
		{
			break;
		}
	}
}
void SayMoneySum()
{
	std::cout << "You currently have " << globalPlayerMoney << " dollaridoos! \n";
}
void SayTableMoney(int aTableState)
{
	if (aTableState == 1)
	{
		std::cout << "This table currently have " << globalTableMoney1 << " dollaridoos! \n";
	}
	else if (aTableState == 2)
	{
		std::cout << "This table currently have " << globalTableMoney2 << " dollaridoos!\n";
	}
	else if (aTableState == 3)
	{
		std::cout << "This table currently have " << globalTableMoney3 << " dollaridoos! \n";
	}
}
void SayInputError()
{
	std::cout << "wrong input!" << std::endl;
}
int InputInt()
{
	int playerInput = {};
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
			isInputActive = false;
			// TODO enum refactor
			return playerInput;
		}
	}
	return playerInput;
}

void Exit()
{
	if (isGlobalTableActive && isGlobalMainActive)
	{
		isGlobalTableActive = false;
	}
	else if (isGlobalTableActive == false && isGlobalMainActive)
	{
		isGlobalMainActive = false;
	}
}
void PrintWinStreak()
{
	int length = globalRatioTrackMax;
	std::cout << "Your win and loss score is: " << std::endl;
	for (int i = length; i > 0; i--)
	{
		std::cout << globalWinRatio[i] << std::endl;
	}
}
void UpdateWinStreak(bool aIsWin)
{
	bool isWin = aIsWin;
	char winValue;
	if (isWin == true)
	{
		winValue = 'W';
	}
	else
	{
		winValue = 'L';
	}

	int length = globalRatioTrackMax;
	for (int i = length; i > 0; i--)
	{
		globalWinRatio[i + 1] = globalWinRatio[i];
		globalWinRatio[i] = winValue;
	}
	PrintWinStreak();
}

void SayTableOutCashed()
{
	std::cout << "You have claimed too much of this table, begone!" << std::endl;
}
bool AmIPoor()
{
	if (globalPlayerMoney <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool IsTablePoor(int aTableState)
{
	//TODO enum refactor
	int tableWinCap = 0;

	switch (aTableState)
	{
		case 1:
		{
			if (globalTableMoney1 <= tableWinCap)
			{
				SayTableOutCashed();
				return true;
			}
			break;
		}
		case 2:
		{
			if (globalTableMoney2 <= tableWinCap)
			{
				SayTableOutCashed();
				return true;
			}
			break;
		}
		case 3:
		{
			if (globalTableMoney3 <= tableWinCap)
			{
				SayTableOutCashed();
				return true;
			}
			break;
		}
		default:
		{
			break;
		}
	}
	return false;
}
int SubCalc(int aValue1, int aSubValue)
{
	//TODO  const args refactor
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

void UpdateMoneyTable(int aBet, int aTableState, bool aIsWin)
{
	int betMoney = aBet;
	int tableState = aTableState; //TODO enum refactor
	bool isWin = aIsWin;
	int tableMultiplier = {};
	int tableBonus = {};
	int tableTotal = {};

	switch (tableState)
	{
		case 1:
		{
			tableBonus = 0;
			tableMultiplier = 2;
			tableTotal = (betMoney * tableMultiplier) + tableBonus;
			if (isWin)
			{
				globalPlayerMoney += tableTotal;
				globalTableMoney1 = SubCalc(globalTableMoney1, tableTotal);
				std::cout << "You WON: " << tableTotal << " moneys!!" << std::endl;
			}
			else
			{
				globalPlayerMoney = SubCalc(globalPlayerMoney, tableTotal);
				globalTableMoney1 += tableTotal;
				std::cout << "You LOST: " << tableTotal << " moneys!!" << std::endl;
			}
			break;
		}
		case 2:
		{
			tableBonus = 55;
			tableMultiplier = 3 % betMoney;
			tableTotal = (betMoney * tableMultiplier) + tableBonus;
			if (isWin)
			{
				globalPlayerMoney += tableTotal;
				globalTableMoney2 = SubCalc(globalTableMoney2, tableTotal);

				std::cout << "You WON: " << tableTotal << " moneys!!" << std::endl;
			}
			else
			{
				globalPlayerMoney = SubCalc(globalPlayerMoney, tableTotal);
				globalTableMoney2 += tableTotal;
				std::cout << "You LOST: " << tableTotal << " moneys!!" << std::endl;
			}
			break;
		}
		case 3:
		{
			tableBonus = 69;
			tableMultiplier = 1;
			tableTotal = (betMoney * tableMultiplier) + tableBonus;
			if (isWin)
			{
				globalPlayerMoney += tableTotal;
				globalTableMoney3 = SubCalc(globalTableMoney3, tableTotal);
				std::cout << "You WON: " << tableTotal << " moneys!!" << std::endl;
			}
			else
			{
				globalPlayerMoney = SubCalc(globalPlayerMoney, tableTotal);
				globalTableMoney3 += tableTotal;
				std::cout << "You LOST: " << tableTotal << " moneys!!" << std::endl;
			}
			break;
		}
	}
	SayTableMoney(tableState);
	SayMoneySum();
}
int RollDie()
{
	std::random_device seed;
	std::mt19937 rndEngine(seed());
	std::uniform_int_distribution<int> rndDist(1, 6);
	int randomNumber = rndDist(rndEngine);
	return randomNumber;
}
int CalcOddEven(int aDie1)
{
	int die1 = aDie1;
	if (die1 % 2 == 1)
	{
		std::cout << "It is Odd!" << std::endl;
		return 1;
	}
	else
	{
		std::cout << "It is Even!" << std::endl;
		return 2;
	}
}
int UpdateBet()
{
	int input;
	int betValue;
	int minBetValue = 0;
	int maxBetValue = globalPlayerMoney;
	bool isBetting = true;

	while (isBetting)
	{
		std::cout << "Whats your bet?" << std::endl;
		std::cin >> input;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			SayInputError();
		}
		else
		{
			if (minBetValue < input && input <= maxBetValue)
			{
				betValue = input;
				std::cout << "You bet: " << betValue << std::endl;

				if (input == maxBetValue)
				{
					std::cout << "Holy Shcmoly! Thats all your money! " << betValue << std::endl;
				}
				isBetting = false;
				return betValue;
			}
			else
			{
				std::cout << "Nope! You can only bet what you have foo! \n You have: " << globalPlayerMoney << ".\n"
					<< "and not below one or negative for queens sake!" << std::endl;
			}
		}
		SayInputError();
		isBetting = true;
	}
	return 0;
}

void BeginGameLogic(int aTableState)
{
	int tableState = aTableState;
	int table1 = 1;
	int table2 = 2;
	int table3 = 3;
	bool isWin = {};
	int betValue = UpdateBet();
	bool isInputActive = false;

	if (tableState == table1)
	{
		int die1;
		int die2;
		int inputTableMin = 2;
		int inputTableMax = 12;
		int DiceSum;
		int playerGuess = 0;

		isInputActive = true;
		die1 = RollDie();
		die2 = RollDie();
		DiceSum = die1 + die2;

		while (isInputActive)
		{
			playerGuess = InputInt();
			if (inputTableMin <= playerGuess && playerGuess <= inputTableMax)
			{
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
				isInputActive = true;
			}
		}
		std::cout << "I rolled: " << die1 << " and " << die2 << '\n'
			<< "Sum: " << die1 + die2 << '\n' << std::endl;
		if (playerGuess != DiceSum)
		{
			isWin = false;
			SayLose();
		}
		else
		{
			isWin = true;
			SayWin();
		}
	}

	else if (tableState == table2)
	{
		int playerGuess = {};
		int inputTableMin = 1;
		int inputTableMax = 2;
		isInputActive = true;
		while (isInputActive)
		{
			playerGuess = InputInt();
			if (playerGuess == inputTableMin)
			{
				isInputActive = false;
			}
			else if (playerGuess == inputTableMax)
			{
				isInputActive = false;
			}
			else
			{
				SayInputError();
			}
		}

		int die1 = RollDie();
		std::cout << "I rolled: " << die1 << std::endl;

		if (playerGuess != CalcOddEven(die1))
		{
			isWin = false;
			SayLose();
		}
		else
		{
			isWin = true;
			SayWin();
		}
	}
	else if (tableState == table3)
	{
		int die1;
		int die2;
		int playerDie1;
		int playerDie2;
		int diceSum;
		int playerDiceSum;
		int differenceValue;

		SayAskReadyToRoll();
		system("pause");
		playerDie1 = RollDie();
		playerDie2 = RollDie();
		playerDiceSum = playerDie1 + playerDie2;

		std::cout << "YOU rolled: " << playerDie1 << " and " << playerDie2 << '\n'
			<< "Sum: " << playerDiceSum << '\n' << std::endl;
		die1 = RollDie();
		die2 = RollDie();
		diceSum = die1 + die2;

		std::cout << "I rolled: " << die1 << " and " << die2 << '\n'
			<< "Sum: " << diceSum << '\n' << std::endl;

		if (playerDiceSum <= diceSum)
		{
			isWin = false;
			differenceValue = diceSum - playerDiceSum;
			std::cout << "It differs by: " << differenceValue << std::endl;
			std::cout << "Yours is not bigger than mine!!" << std::endl;
			SayLose();
		}
		else if (playerDiceSum > diceSum)
		{
			isWin = true;
			differenceValue = playerDiceSum - diceSum;
			std::cout << "It differs by: " << differenceValue << std::endl;
			std::cout << "Yours is bigger than mine!" << std::endl;
			SayWin();
		}
	}
	UpdateMoneyTable(betValue, tableState, isWin);
	UpdateWinStreak(isWin);
}
void EnterTable(int aTableState)
{
	int tableState = aTableState;
	int tableMenu;
	isGlobalTableActive = true;

	while (isGlobalTableActive && AmIPoor() == false && IsTablePoor(tableState) == false)
	{
		SayTableMenu();
		tableMenu = InputInt();
		switch (tableMenu)
		{
			case 0:
			{
				Exit();
				break;
			}
			case 1:
			{
				BeginGameLogic(tableState);
				break;
			}
			case 2:
			{
				SayRulesTable(tableState);
				break;
			}
			case 3:
			{
				PrintWinStreak();
				break;
			}

			default:
			{
				SayInputError();
				break;
			}
		}
	}
}
void GameState(int aTableState)
{
	//TODO enum refactor
	int tableState = aTableState;

	switch (tableState)
	{
		case 0:
		{
			Exit();
			break;
		}
		case 1:
		case 2:
		case 3:
		{
			SayGreetingTable(tableState);
			SayTableTreshold(tableState);
			SayMoneySum();
			EnterTable(tableState);
			break;
		}
		case 4:
		{
			PrintWinStreak();
			break;
		}
		default:
		{
			SayInputError();
			break;
		}
	}
}

int main()
{
	isGlobalMainActive = true;
	SayEnterCasino();
	while (isGlobalMainActive && AmIPoor() == false)
	{
		SayMainMenuChoices();
		GameState(InputInt());
	}
};