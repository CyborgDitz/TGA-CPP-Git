#include <iostream>

namespace Library
{
	int SetInput(const int aInputMin, const int aInputMax)
	{
		int inputInt{};
		const int inputMin = aInputMin;
		const int inputMax = aInputMax;
		while (true)
		{
			std::cout << "Choice: " << std::endl;
			std::cin >> inputInt;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "Please enter a number between " << inputMin << " and " << inputMax << std::endl;
			}
			else if (inputMin <= inputInt && inputInt <= inputMax)
			{
				return inputInt;
			}
			else
			{
				std::cout << "Please enter a number between " << inputMin << " and " << inputMax << std::endl;
			}
		}
	};

	void SayRoomMenu()
	{
		std::cout << "These are the choices" << std::endl;
		std::cout << "1:Open Door \t 2: Attack the Monsters! \t 3: Cast spells \t 4: Explore! 5: See your stats "<<std::endl;
		std::cout << "or 0 for the secret go to the menu Exit state" << std::endl;
	}
}
