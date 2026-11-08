#include "Input.h"
#include "windows.h"
#include "winuser.h"
#include "wincon.h"

/* https://stackoverflow.com/questions/9326364/how-to-get-direct-keyboard-input-in-c  source */

namespace CommonUtilities
{

	int getkey() {

		for (int i = 1; i < 255; ++i) 
		{
			// The bitwise and selects the function behavior (look at doc)
			if (GetAsyncKeyState(i) & 0x07)
			{
				return i;
			}


		}
	}
	bool Input::UpdateEvents(UINT message, WPARAM wParam, LPARAM lParam)
	{
		/*-Update Events gets message and param
			-- IsKeyPressed" gets wParam IF message is WM_KeyDown
			-- IsMousePressed gets wParam if Message is MOUSEEVENTF_XDOWN*/
			//
		switch (message)
		{
		case (WM_KEYDOWN):
		{
			myIsKeyHandled = IsKeyPressed(wParam);
			while (WM_KEYDOWN)
			{
				return IsKeyDown(wParam);
			}
			break;
		}
		case(WM_KEYUP):
		{
			myIsKeyHandled = IsKeyReleased(wParam);
			break;
		}

		case (MOUSEEVENTF_XDOWN):
		{
			myIsKeyHandled = IsMouseButtonPressed(wParam);
			break;
		}

		}

		return myIsKeyHandled;
	}

	bool Input::IsKeyPressed(const int aKeyCode) const
	{
		if (GetAsyncKeyState(aKeyCode) < 0)
		{
			return true;
		}

		return false;
	}

	bool Input::IsKeyDown(const int aKeyCode) const
	{

		// key is down
		while (IsKeyPressed(aKeyCode)) //not up
		{
			return 1;
		}

		return 0;
	}
	bool Input::IsKeyReleased(const int aKeyCode) const
	{


		//key needs to have been down and then send bool when released
		if (IsKeyDown(aKeyCode) == true)
		{
			return true;

		}
		else if (IsKeyPressed(aKeyCode) == false && IsKeyDown(aKeyCode) == true)
		{
			return false;
		}
		return true;
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