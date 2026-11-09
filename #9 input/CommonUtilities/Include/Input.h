#pragma once
#include "Input.h"
#include "windows.h"
#include "winuser.h"
#include "wincon.h"
namespace CommonUtilities
{


	class Input
	{
	public:

		struct MousePos
		{
			int xPos = {};
			int yPos ={};
		};
		bool IsKeyPressed(const int aKeyCode) const;
		bool IsKeyReleased(const int aKeyCode) const;
		bool IsKeyDown(const int aKeyCode) const;
		bool IsMouseButtonPressed(const int aKeyCode) const;
		bool IsMouseButtonDown(const int aKeyCode) const;
		bool IsMouseButtonReleased(const int aKeyCode) const;
		bool GetMousePosition(UINT message) const;


		int  GetKey(const WPARAM aKeyCode) const;

		bool UpdateEvents(UINT message, WPARAM wParam, LPARAM lParam);
		private:
	
			bool myOtherKey = false;

		bool myIsKeyHandled = false;
	};



}
