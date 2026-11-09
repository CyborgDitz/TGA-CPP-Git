#include <cassert>

namespace CommonUtilities
{

	template<typename T>T Max(T a, T b)
	{
		return (a > b ? a : b);
	}
	template<typename T>T Min(T a, T b)
	{
		return (a < b ? a : b);
	}
	template<typename T>T Abs(T a)
	{
		
		if (a < 0)
		{
			return (a * -1);
		}
		
			return (a);
	}

	template<typename T>T Clamp(T value, T min, T max)
	{
		
		if (value < 0 || min < 0 || max < 0)
		{
			if (value > 0 && max > 0)
			{
				return (value < max ? value : max);
			}
			return (value > min ? max : min);
		}
	
		if (max != min)
		{
			return (value > min ? value : min);

		}

		return max;
	
	
	}

	template<typename T>T Lerp(T a, T b, float c)
	{

		return static_cast<T>(a + c *(b - a));
	}
	template<typename T>void Swap(T &a, T &b)
	{
		T c = a;
		a = b;
		b = c;
	
	}
}
