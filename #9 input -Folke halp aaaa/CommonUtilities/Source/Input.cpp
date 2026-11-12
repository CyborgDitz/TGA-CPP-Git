#include "Input.h"
#include "windows.h"
#include "winuser.h"
#include "wincon.h"
#include <Windowsx.h>

namespace CommonUtilities
{

	int Input::GetKey(const WPARAM wParam) const
	{
		
		if (0 < wParam && wParam < myKeyMax)
		{
			return (static_cast<int>(wParam));
		}
		return 0;
	}
	bool Input::UpdateEvents(UINT message, WPARAM wParam, LPARAM lParam)
	{
		
		{//qrikketed
			myOldKey = myCurrentKey;
			myOldMouseKey = myMouseKey;
		}
		switch (message)
		{
		case (WM_KEYDOWN):
		{
			bool isKeyDown = IsKeyDown(GetKey(wParam));

			while (isKeyDown == true)
			{
				return myCurrentKey[isKeyDown, wParam];
			}
			break;
		}
		case(WM_KEYUP):
		{
			return myCurrentKey[IsKeyReleased(GetKey(wParam)), wParam];
			break;
		}
	
		case (WM_LBUTTONDOWN):
		{
			return myMouseKey[VK_LBUTTON] = true;
			break;
		}
		case (WM_LBUTTONUP):
		{
			return myMouseKey[VK_LBUTTON] = false;
			break;
		}
		case (WM_RBUTTONDOWN):
		{
			return myMouseKey[VK_RBUTTON] = true;
			break;
		}
		case (WM_RBUTTONUP):
		{
			return myMouseKey[VK_RBUTTON] = false;
			break;
		}
		case (WM_MBUTTONDOWN):
		{
			return myMouseKey[VK_MBUTTON] = true;
			break;
		}
		case (WM_MBUTTONUP):
		{
			return myMouseKey[VK_MBUTTON] = false;
			break;
		}
		case(WM_MOUSEMOVE):
		{
			return GetMousePosition(WM_MOUSEMOVE);
		
			break;
		}
		default:
		{
			return false;
		}

		return true;
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
		
			return myCurrentKey[false,aKeyCode] && myOldKey[true,aKeyCode];

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

		bool Input::GetMousePosition(UINT message)
		{
			myMouse.myCurrentPos.x = GET_X_LPARAM(message);
			myMouse.myCurrentPos.y = GET_Y_LPARAM(message);
			return true;
		}

		//POINT ::Input::GetMousePosition() const
		//{
		// // if (point =< vector.x)(point = vector.x/*screensize.x/*)
		//	 // if (point =< vector.y)(point = vector.y/*screensize.y/*)
		//	return POINT();
		//}

	
}