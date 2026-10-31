#include "pch.cpp"

///IDE Configs
//find h files
// set library folders to use
// use h files only when selected
// find dlls

void CommonUtilities::Timer::Update()
{
	//run once per frame only, runs first
}

float CommonUtilities::Timer::GetDeltaTime() const
{
	//time/frames
	//  use GetTotalTime() last frame, and this frame and minus
	return 0.0f;

}

double CommonUtilities::Timer::GetTotalTime() const
{	std::chrono::high_resolution_clock::time_point timemyTotalTime = std::chrono::high_resolution_clock::now();
	//std::chrono::duration<double> myTotalTime = std::chrono::duration_cast<std::chrono::duration<double>>(myTitty2 - myTitty1);
	std::chrono::duration<double> myTotalTime =  std::chrono::duration<double>(myTotalTime);
	return myTotalTime;
}

int CommonUtilities::Timer::GetFixedRateTickDeltaCount() const
{
	//use titty1 or tity2?
	return 0;
}

uint64_t CommonUtilities::Timer::GetFixedRateTickCount() const
{
	return 0;
}
