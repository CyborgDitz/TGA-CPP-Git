#include "Input.h"
#include "windows.h"
#include "winuser.h"
#include "wincon.h"
#include <Windowsx.h>

namespace CommonUtilities
{

	int  Input::GetKey(const WPARAM wParam) const
	{
		
		if (0 < wParam && wParam < myKeyMax)
		{
			return (wParam);
		}
		return 0;
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
			bool isKeyDown = IsKeyDown(GetKey(wParam));

			while (isKeyDown == true)
			{
				return myCurrentKey[isKeyDown, wParam];
			}
			break;
		}
		case(WM_KEYUP):
		{
			myCurrentKey[IsKeyReleased(GetKey(wParam)), wParam];
			break;
		}
	
		case (WM_LBUTTONDOWN):
		{
			myState[VK_LBUTTON] = true;
			break;
		}
		case (WM_LBUTTONUP):
		{
			myState[VK_LBUTTON] = false;
			break;
		}
		case (WM_RBUTTONDOWN):
		{
			myState[VK_RBUTTON] = true;
			break;
		}
		case (WM_RBUTTONUP):
		{
			myState[VK_RBUTTON] = false;
			break;
		}
		case (WM_MBUTTONDOWN):
		{

			myState[VK_MBUTTON] = true;
			break;
		}
		case (WM_MBUTTONUP):
		{
			myState[VK_MBUTTON] = false;
			break;
		}
		case(WM_MOUSEMOVE):
		{
			GetMousePosition(WM_MOUSEMOVE);
			myMouse.myCurrentPos.x = GET_X_LPARAM(lParam);
			myMouse.myCurrentPos.y = GET_Y_LPARAM(lParam);
			break;
		}


		return true;
		}
	}
		bool Input::IsKeyPressed(const int aKeyCode) const
		{
			return myState[true,aKeyCode];
		}

		bool Input::IsKeyDown(const int aKeyCode) const
		{
			return myState[true, aKeyCode] && myOldKey[false, aKeyCode];
		}
		bool Input::IsKeyReleased(const int aKeyCode) const
		{
		
			return myCurrentKey[false,aKeyCode] && myOldKey[true,aKeyCode];

		}

		bool Input::IsMouseButtonDown(const int aKeyCode) const
		{

			return myState[true, aKeyCode];
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
			//return myMouse.myCurrentPos;
		}

		//POINT ::Input::GetMousePosition() const
		//{
		// // if (point =< vector.x)(point = vector.x/*screensize.x/*)
		//	 // if (point =< vector.y)(point = vector.y/*screensize.y/*)
		//	return POINT();
		//}

	
}