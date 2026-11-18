#include "Input.h"
#include "windows.h"
#include "winuser.h"
#include "wincon.h"
#include <Windowsx.h>
#include <cstdio>
#include <iostream>
namespace CommonUtilities
{
	
	const int Input::GetKeyCode(const WPARAM wParam) const
	{

		if (0 < wParam && wParam <= myKeyMax)
		{
			return (wParam);
		}
		return 0;
	}
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

			myOldKey = myCurrentKey;
			myOldMouseKey = myMouseKey;

			myMouse.deltaWheel = myMouse.currentWheel - myMouse.previousWheel;
			myMouse.previousWheel = myMouse.currentWheel;
		}
		if (isValid == true)
		{
			switch (message)
			{
				case (WM_KEYDOWN):
				{
					myCurrentKey[ wParam] =true;
					break;
				}
				case(WM_KEYUP):
				{
					myCurrentKey[ wParam] = false;
					break;

				case (WM_LBUTTONDOWN):
				{
					myMouseKey[ VK_LBUTTON]= true;
					break;
				}
				case (WM_LBUTTONUP):

					return myMouseKey[ VK_LBUTTON] = false ;
					break;
				}
				case (WM_RBUTTONDOWN):
				{
					return myMouseKey[VK_RBUTTON] = true;
					break;
				}
				case (WM_RBUTTONUP):
				{
					return 	myMouseKey[ VK_RBUTTON] = true;
					break;
				}
				case (WM_MBUTTONDOWN):
				{
					return myMouseKey[ VK_MBUTTON] = true ;
					break;
				}
				case (WM_MBUTTONUP):
				{
					return myMouseKey[ VK_MBUTTON] = false;
					break;
				}
				case(WM_MOUSEMOVE):
				{
					 UpdateMousePosition(WM_MOUSEMOVE);
					break;
				}
				default:
				{
					 	isValid = false;
					break;
				}
			}
				return isValid;
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

		myMouse.myCurrentPos.x = GET_X_LPARAM(message);
		myMouse.myCurrentPos.y = GET_Y_LPARAM(message);

		myMouse.myPosDelta = myMouse.myCurrentPos;

		myMouse.myPosDelta.x = myMouse.myCurrentPos.x - myMouse.myOldPos.x;
		myMouse.myPosDelta.y = myMouse.myCurrentPos.y - myMouse.myOldPos.y;
	}

}