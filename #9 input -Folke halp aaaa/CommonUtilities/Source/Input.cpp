#include "Input.h"
#include "windows.h"
#include "winuser.h"
#include "wincon.h"
#include <Windowsx.h>

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
			for (size_t i = 0; i < myOldKey.size(); i++)
			{
				myOldKey = myCurrentKey;
				myOldMouseKey = myMouseKey;
			}
			myMouse.deltaWheel = myMouse.currentWheel - myMouse.previousWheel;
			myMouse.previousWheel = myMouse.currentWheel;
		}
		if (isValid == true)
		{
			switch (message)
			
			{
				case (WM_KEYDOWN):
				{
					myCurrentKey[isValid, wParam];
					break;
				}
				case(WM_KEYUP):
				{
					myCurrentKey[!isValid, wParam];
					break;
				
				case (WM_LBUTTONDOWN):
				{
					myMouseKey[isValid, VK_LBUTTON];
					break;
				}
				case (WM_LBUTTONUP):
				
					myMouseKey[!isValid, VK_LBUTTON];
					break;
				}
				case (WM_RBUTTONDOWN):
				{
					myMouseKey[isValid, VK_RBUTTON];
					break;
				}
				case (WM_RBUTTONUP):
				{
					myMouseKey[!isValid, VK_RBUTTON];
					break;
				}
				case (WM_MBUTTONDOWN):
				{
					myMouseKey[isValid, VK_MBUTTON];
					break;
				}
				case (WM_MBUTTONUP):
				{
					myMouseKey[!isValid, VK_MBUTTON];
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
				}
			}
				return isValid;
		}
	}
	bool Input::IsKeyPressed(const int aKeyCode) const
	{
		return myCurrentKey[true, aKeyCode] && myOldKey[false, aKeyCode];
	}

	bool Input::IsKeyDown(const int aKeyCode) const
	{
		return myCurrentKey[true, aKeyCode] && myOldKey[true, aKeyCode];
	}
	bool Input::IsKeyReleased(const int aKeyCode) const
	{

		return myCurrentKey[false, aKeyCode] && myOldKey[true, aKeyCode];

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