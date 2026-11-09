#include <iostream>
#include <random>
#include "PrintCasino.h" 

int playerMoney = 9999;
bool isMainActive = true;
enum GameState
{
	Exit,
	MainMenu,
	GuessSum,
	OddEven,

};
bool AmIPoor(int aPlayersMoney)
{
	int noMoney = 0;
	int playerMoney = aPlayersMoney;

	if (playerMoney <= noMoney)
	{
		std::cout << "Get out of our casino you poor fool!" << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}
bool QueryReplay()
{
	char playerInput;
	bool isQueryActive = true;

	while (isQueryActive == true)
	{
		SayPlayAgain();
		std::cin >> playerInput;
		std::cin.ignore(1000, '\n');
		if (std::cin.fail())
		{
			SayInputError();
		}
		else
		{
			if (playerInput == 'Y' || playerInput == 'y')
			{
				isQueryActive = false;
				return  true;
			}
			else if (playerInput == 'N' || playerInput == 'n')
			{
				isQueryActive = false;
				return false;
			}
			else
			{
				SayInputError();
			}
		}
	}
	return 0;
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

int RunGuessSum()
{
	bool isUpdateActive = true;
	int playerNumberGuess = 0;
	int returnValue;

	SayRulesSum();

	while (isUpdateActive == true)
	{
		std::cin >> playerNumberGuess;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			SayInputError();
		}
		else if (playerNumberGuess < 2 || playerNumberGuess >12)
		{
			SayInputError();
		}
		else
		{
			std::cout << "You picked: " << playerNumberGuess << std::endl;
			isUpdateActive = false;
		}
	}

	return returnValue = playerNumberGuess;
}

int RollDice()
{
	std::random_device seed;
	std::mt19937 rndEngine(seed());
	std::uniform_int_distribution<int> rndDist(1, 6);
	int randomNumber = rndDist(rndEngine);
	return randomNumber;
}

int UpdateBet()
{
	int input;
	int betValue;
	int minBetValue = 0;
	int maxBetValue = playerMoney;

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
		bool isBetting = true;
		while (isBetting)
			if (minBetValue < input <= maxBetValue)
			{
				betValue = input;
				std::cout << "You bet: " << betValue << std::endl;

				if (betValue == playerMoney)
				{
					std::cout << "Holy Schmoly thats all your dollars!" << std::endl;
				}
				isBetting = false;
				return betValue;
			}
	}
}
int RunOddEven()
{
	bool isUpdateActive = true;
	int playerNumberGuess = 0;
	int minValue = 1;
	int maxValue = 2;
	int returnValue;

	SayRulesOddEven();

	while (isUpdateActive == true)
	{
		std::cin >> playerNumberGuess;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			SayInputError();
		}
		else if (playerNumberGuess < minValue || playerNumberGuess > maxValue)
		{
			SayInputError();
		}
		else if (playerNumberGuess == minValue)
		{
			std::cout << "You picked: odd!" << std::endl;
			isUpdateActive = false;
		}
		else if (playerNumberGuess == maxValue)
		{
			std::cout << "You picked: even!" << std::endl;
			isUpdateActive = false;
		}
	}

	return returnValue = playerNumberGuess;
}
void UpdateMoneyGuessSum(int aValue, bool aIsWin)
{
	int addedMoney = aValue;
	bool isWin = aIsWin;
	int tableMultiplier = 2;
	int tableTotal = tableMultiplier * addedMoney;
	if (isWin)
	{
		playerMoney += tableTotal;
		std::cout << "You WON: " << tableTotal << " moneys!!" << std::endl;
	}
	else
	{
		int subMin = 0;
		playerMoney -= tableTotal;
		if (playerMoney < subMin)
		{
			playerMoney = subMin;
		}
		std::cout << "You LOST: " << tableTotal << " moneys!!" << std::endl;
	}

	SayMoneySum(playerMoney);
}
void UpdateMoneyOddEven(int aValue, bool aIsWin)
{
	bool isWin = aIsWin;
	int addedMoney = aValue;
	int tableMultiplier = 1;
	int tableTotal = tableMultiplier * addedMoney;

	if (isWin)
	{
		playerMoney += tableTotal;
		std::cout << "You WON: " << tableTotal << " moneys!!" << std::endl;
	}
	else
	{
		int subMin = 0;
		playerMoney -= tableTotal;
		if (playerMoney < subMin)
		{
			playerMoney = subMin;
		}
		std::cout << "You LOST: " << tableTotal << " moneys!!" << std::endl;
	}

	SayMoneySum(playerMoney);
}
void GameGuessSum(int aPlayerValue, int aBet, int aDie1, int aDie2)
{
	bool isWin;
	int die1;
	int die2;
	int DiceSum;
	int betValue = aBet;

	die1 = aDie1;
	die2 = aDie2;
	DiceSum = die1 + die2;
	std::cout << "I rolled: " << die1 << " and " << die2 << '\n'
		<< "Sum: " << die1 + die2 << '\n' << std::endl;
	if (aPlayerValue != DiceSum)
	{
		isWin = false;
		SayLose();
	}
	else
	{
		isWin = true;
		SayWin();
	}
	UpdateMoneyGuessSum(betValue, isWin);
}
void GameOddEven(int aInputValue, int aBet, int aDie1)
{
	bool isWin;
	int playerOdd = aInputValue;
	int die1 = aDie1;
	int betValue = aBet;

	std::cout << "I rolled: " << die1 << std::endl;

	if (playerOdd != CalcOddEven(die1))
	{
		isWin = false;
		SayLose();
	}
	else
	{
		isWin = true;
		SayWin();
	}
	UpdateMoneyOddEven(betValue, isWin);
}
void StartGame()
{
	std::cout << "the game has begun!!" << std::endl;
}

void EnterTable2()
{
	SayMoneySum(playerMoney);
	GameOddEven(RunOddEven(), UpdateBet(), RollDice());
}
void EnterTable1()
{
	SayMoneySum(playerMoney);
	GameGuessSum(RunGuessSum(), UpdateBet(), RollDice(), RollDice());
}
void SelectGame(int aGameState)
{

	int gameRoom = aGameState;
	switch (gameRoom)
	{
		case 0:
		{
			SayByeCasino(playerMoney);
			isMainActive = false;
			break;
		}
		case 1:
		{
			std::cout << "Guess Game!!" << std::endl;

			int input;
			bool isActive = true;

			while (isActive && AmIPoor(playerMoney) == false)
			{
				std::cout << "1: Play the game. 2: Show Rules. 0: Leave and go back to Main Menu" << std::endl;
				std::cin >> input;
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(1000, '\n');
					SayInputError();
				}
				else if (input == 1)
				{
					EnterTable1();

				}
				else if (input == 2)
				{
					SayRulesSum();
				}
				else if (input == 0)
				{
					isActive = false;
				}
				else
				{
					SayInputError();
				}
			}
			break;
		}
		case 2:
		{
			std::cout << "Odd or Even!" << std::endl;

			int input;
			bool isActive = true;

			while (isActive && AmIPoor(playerMoney) == false)
			{
				std::cout << "1: Play the game. 2: Show Rules. 0: Leave and go back to Main Menu" << std::endl;
				std::cin >> input;
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(1000, '\n');
					SayInputError();
				}
				else
				{

					if (input == 1)
					{
						EnterTable2();
					}
					else if (input == 2)
					{
						SayRulesOddEven();
					}
					else if (input == 0)
					{
						isActive = false;
					}
					else
					{
						SayInputError();
					}
				}
			}
			break;
		}
		default:
		{
			SayInputError();
			break;
		}
	}
}
int MainMenuInput()
{
	int menuChoice;

	while (isMainActive && AmIPoor(playerMoney) == false)
	{
		{
			bool isInputActive = true;
			while (isInputActive == true)
			{
				std::cin >> menuChoice;
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(1000, '\n');
					SayInputError();
				}
				else
				{
					switch (menuChoice)
					{
						case 0:
						{
							isInputActive = false;
							return 0;
							break;
						}
						case 1:
						{
							isInputActive = false;
							return 1;
							break;
						}
						case 2:
						{
							isInputActive = false;
							return 2;
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
		}
	}
}
int main()
{
	isMainActive = true;
	SayEnterCasino();
	while (isMainActive)
	{
		if (AmIPoor(playerMoney) == true)
		{
			isMainActive = false;
		}
		else
		{
			SayMainMenu();
			SelectGame(MainMenuInput());
		}
	}
}