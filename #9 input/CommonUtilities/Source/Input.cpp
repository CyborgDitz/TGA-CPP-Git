#include "Input.h"
#include "windows.h"
#include "winuser.h"
#include "wincon.h"
#include <Windowsx.h>


/* https://stackoverflow.com/questions/9326364/how-to-get-direct-keyboard-input-in-c  source */

namespace CommonUtilities
{

	int  Input::GetKey(const WPARAM aKeyCode) const
	{
		const int maxKey = 255;

		// The bitwise and selects the function behavior (look at doc)
		if (0 < aKeyCode && aKeyCode < maxKey)
		{
			return static_cast<int>(aKeyCode);
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
			myIsCurrentKey = IsKeyDown(GetKey(wParam));

			while (WM_KEYDOWN)
			{
				return IsKeyDown(GetKey(wParam));
			}
			break;
		}
		case(WM_KEYUP):
		{
			myIsCurrentKey = IsKeyReleased(GetKey(wParam));
			break;
		}

		case (WM_LBUTTONDOWN):
		{
			myIsCurrentKey = IsMouseButtonPressed(GetKey(wParam));
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
			myMouse.posX = GET_X_LPARAM(lParam);
			myMouse.posY = GET_Y_LPARAM(lParam);
			break;
		}


		return myIsCurrentKey;
		}
	}
		bool Input::IsKeyPressed(const int aKeyCode) const
		{
			if (0 == aKeyCode)
			{
				return false;
			}

			return true;
		}

		bool Input::IsKeyDown(const int aKeyCode) const
		{

			// key is down
			while (myIsCurrentKey == true) //not up
			{
				return true;
			}

			return false;
		}
		bool Input::IsKeyReleased(const int aKeyCode) const
		{


			//key needs to have been down and then send bool when released
			return (myIsCurrentKey)
			{
				return 

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