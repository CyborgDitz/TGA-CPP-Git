#pragma once
#include "pch.h"
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
			std::chrono::high_resolution_clock::time_point myTitty1 = std::chrono::high_resolution_clock::now();
			//call t1, do stuff between, call t2, t2 -1 = timespanofAssFuck
			std::chrono::high_resolution_clock::time_point myTitty2 = std::chrono::high_resolution_clock::now();
			//it took me timespanofAssFuck get herwe;
			float myDeltaTime{};
			double myTotalTime;
			int myFixedRateTickDeltaCount{};
			uint64_t myFixedRateTickCount{};
	};
	// std chrono clock Returns the current time_point in the frame of the high_resolution_clock.
}