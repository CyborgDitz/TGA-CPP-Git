#include "pch.cpp"
#include "Timer.h"
#include "framework.h"
///IDE Configs
//find h files
// set library folders to use
// use h files only when selected
// find dlls

CommonUtilities::Timer::Timer(float aFixedTickTime) : myClockTime(std::chrono::high_resolution_clock())
{
	
	myFixedTickTime = aFixedTickTime;
}

void CommonUtilities::Timer::Update()
{
	myDeltaTime = myClockTime.now();
}

float CommonUtilities::Timer::GetDeltaTime() const
{
	//time/frames
	//  use GetTotalTime() last frame, and this frame and minus delta time
	return std::chrono::duration<float>(myClockTime.now() - myDeltaTime).count();

}

double CommonUtilities::Timer::GetTotalTime() const
{	std::chrono::high_resolution_clock::time_point myTotalTimemyTotalTime = myClockTime.now();
	
return std::chrono::duration(myClockTime.now() - myTimeNow).count();
}

int CommonUtilities::Timer::GetFixedRateTickDeltaCount() const
{

	return static_cast<uint64_t>(GetDeltaTime() - myFixedTickTime);

}

uint64_t CommonUtilities::Timer::GetFixedRateTickCount() const
{
	return static_cast<uint64_t>(GetTotalTime() - myFixedTickTime);
	
}


