#include "Input.h"
#include "windows.h"
#include "winuser.h"
#include "wincon.h"
#include <Windowsx.h>
#include <cstdio>
#include <iostream>
namespace CommonUtilities
{
	

	bool Input::IsKeyValid(const WPARAM wParam) const
	{
		if (0 < wParam && wParam <= myKeyMax)
		{
			
			return true;
		}
		return false;
	}
	bool Input::UpdateEvents(UINT message, WPARAM wParam, LPARAM lParam)
	{
		bool isValid = IsKeyValid(wParam);

		{//qrikketed
			myStoredKey = myCurrentKey;
			myOldKey = myCurrentKey;
			myOldMouseKey = myMouseKey;

			Input::UpdateMousePosition(message);
		}
		if (isValid == true)
		{
			
			switch (message)
			{
			case (WM_KEYDOWN):
			{
				myStoredKey[wParam] = true;
				break;
			}
			case(WM_KEYUP):
			{
				myStoredKey[wParam] = false;
				break;

			
			}
			case WM_MOUSEWHEEL: 
			{
				float wheelDelta = GET_WHEEL_DELTA_WPARAM(wParam);
				myMouse.currentWheel += wheelDelta;
				return true;
			}
			case(WM_MOUSEMOVE):
			{
				UpdateMousePosition(WM_MOUSEMOVE);
				break;
			}
			default:
			{
				return  false;

			}
			}
		}
	}
	bool Input::IsKeyPressed(const int aKeyCode) const
	{
		return myCurrentKey[aKeyCode] == true && myOldKey[aKeyCode] == false;
	}

	bool Input::IsKeyDown(const int aKeyCode) const
	{
		return myCurrentKey[aKeyCode] == true && myOldKey[aKeyCode] == true;
	}
	bool Input::IsKeyReleased(const int aKeyCode) const
	{

		return myCurrentKey[aKeyCode] == false && myOldKey[aKeyCode] == true;

	}

	bool Input::IsMouseButtonDown(const int aKeyCode) const
	{
		return myMouseKey[true, aKeyCode] && myOldMouseKey[false, aKeyCode];
	}

	bool Input::IsMouseButtonPressed(const int aKeyCode) const
	{
		return myMouseKey[true, aKeyCode] && myOldMouseKey[true, aKeyCode];
	}

	bool Input::IsMouseButtonReleased(const int aKeyCode) const
	{
		return myMouseKey[false, aKeyCode] && myOldMouseKey[true, aKeyCode];
	}

	void Input::UpdateMousePosition(UINT message)
	{
		myMouse.myOldPos = myMouse.myCurrentPos;

		myMouse.myPosDelta = myMouse.myCurrentPos;

		myMouse.myPosDelta.x -= myMouse.myOldPos.x;
		myMouse.myPosDelta.y -= myMouse.myOldPos.y;

		

		myMouse.deltaWheel = myMouse.currentWheel - myMouse.previousWheel;
		myMouse.previousWheel = myMouse.currentWheel;
	}

}