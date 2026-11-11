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
			myCurrentKey[ IsKeyDown(GetKey(wParam)), wParam];

			while (WM_KEYDOWN)
			{
				return IsKeyDown(GetKey(wParam));
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
			myCurrentKey[IsMouseButtonPressed(GetKey(wParam)), wParam];
			break;
		}
		case (WM_LBUTTONUP):
		{
			break;
		}
		case (WM_MBUTTONDOWN):
		{
			break;
		}
		case (WM_MBUTTONUP):
		{
			break;
		}
		case(WM_MOUSEMOVE):
		{
			GetMousePosition(WM_MOUSEMOVE);
			myMouse.myCurrentPos.x = GET_X_LPARAM(lParam);
			myMouse.myCurrentPos.y = GET_Y_LPARAM(lParam);
			break;
		}


		return 0;
		}
	}
		bool Input::IsKeyPressed(const int aKeyCode) const
		{
			return myState[true,aKeyCode];
		}

		bool Input::IsKeyDown(const int aKeyCode) const
		{
			return myState[true, aKeyCode] && myOldKey[false, aKeyCode]
		}
		bool Input::IsKeyReleased(const int aKeyCode) const
		{
		
			return myCurrentKey[false,aKeyCode] && myOldKey[true,aKeyCode];

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