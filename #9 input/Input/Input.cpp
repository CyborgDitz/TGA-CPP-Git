#include "Input.h"
#include "windows.h"
#include "winuser.h"
#include "wincon.h"
/* https://stackoverflow.com/questions/9326364/how-to-get-direct-keyboard-input-in-c  source */

namespace CommonUtilities
{
	bool Input::UpdateEvents(UINT message, WPARAM wParam, LPARAM lParam)
	{
		if (message == WM_KEYDOWN)
		{
		return false;

		}
	}
	int Input::GetKey() const
	{
		while (true)
		{
			for (int i = 1; i < 255; ++i)
			{
				// The bitwise and selects the function behavior (look at doc)
				if (GetAsyncKeyState(i) & 0x07)
					return i;

			}

			Sleep(250);
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
		if (IsKeyPressed(aKeyCode) == true) &&
			return false;
	}

	bool Input::IsKeyReleased(const int aKeyCode) const
	{
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