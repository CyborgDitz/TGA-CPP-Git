
#include "Timer.h"
#include <Windows.h>
#include <iostream>


int main() 
{

	using namespace CommonUtilities;
	Timer timer;
	while(true)
	{
		timer.Update();
		
		Sleep(1000);

		std::cout << "The DeltaTime: " << timer.GetDeltaTime() << std::endl; 
		std::cout << "The Time Total  " << timer.GetTotalTime() << std::endl;
	}
	return 0;
}