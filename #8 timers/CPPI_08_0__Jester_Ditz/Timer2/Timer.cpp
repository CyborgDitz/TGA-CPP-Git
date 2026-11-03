#include "Timer.h"
#include <Windows.h>
#include <iostream>


int main() 
{

	using namespace CommonUtilities;
	Timer timer;
	for (int i = 0; i < 10; i++)
	{
		timer.Update();
		
		Sleep(10);

		std::cout << "The DeltaTime: " << timer.GetDeltaTime() << std::endl; 
		std::cout << "The Time Total  " << timer.GetTotalTime() << std::endl;
	}
	return 0;
}