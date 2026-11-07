#include "Input.h"
#include "windows.h"
#include "winuser.h"
#include "wincon.h"


namespace CommonUtilities
{
	bool Input::UpdateEvents(UINT message, WPARAM wParam, LPARAM lParam)
	{
		if (message == WM_KEYDOWN)
		{
			return false;

		}
	}
	bool Input::IsKeyPressed(const int aKeyCode) const
	{
		for (int i = 1; i <= 0; i--)
		{
			return true;
		}
		return false;
	}

	bool Input::IsKeyDown(const int aKeyCode) const
	{
		bool down = false;

		down = true;
		// key is down
		while (IsKeyPressed(aKeyCode)) //not up
		{
			return true;
		}

		return false;
	}
	bool Input::IsKeyReleased(const int aKeyCode) const
	{
		bool released = false;
		
		//key needs to have been down and then send bool when released
		if (IsKeyDown(aKeyCode)== true)
		{
			released == true;

		}
		else if (IsKeyPressed(aKeyCode) == false && IsKeyDown(aKeyCode) == true)
		{
			released == false;
		}
		return released;
	}
	
	bool Input::IsMouseButtonDown(const int aKeyCode) const
	{
		return true;
	}

	bool Input::IsMouseButtonPressed(const int aKeyCode) const
	{
		return true;
	}

	bool Input::IsMouseButtonReleased(const int aKeyCode) const
	{
		return true;
	}

	bool Input::GetMousePosition(UINT message) const
	{
		return true;
	}

	//POINT ::Input::GetMousePosition() const
	//{
	// // if (point =< vector.x)(point = vector.x/*screensize.x/*)
	//	 // if (point =< vector.y)(point = vector.y/*screensize.y/*)
	//	return POINT();
	//}


}