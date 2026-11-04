#pragma once

#include <cstdint>
#include <chrono>
#include <ctime>
#include <ratio>
namespace CommonUtilities
{
	class Timer
	{
	public:
		Timer(float aFixedTickTime = 1.f / 60.f);
		Timer(const Timer& aTimer) = delete;
		Timer& operator=(const Timer& aTimer) = delete;
		void Update();
		float GetDeltaTime() const;
		double GetTotalTime() const;
		int GetFixedRateTickDeltaCount() const;
		uint64_t GetFixedRateTickCount() const;

		private:
			const std::chrono::high_resolution_clock myClockTime;
	
			const std::chrono::high_resolution_clock::time_point myTimeNow;
			 std::chrono::high_resolution_clock::time_point myDeltaTime;
			
		
			float myFixedTickTime;
	};
	// std chrono clock Returns the current time_point in the frame of the high_resolution_clock.
}