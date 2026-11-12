#pragma once
#include "Input.h"
#include "windows.h"
#include "winuser.h"
#include "wincon.h"
#include <array>
namespace CommonUtilities
{
	struct Vector2Pos
	{
		int x = {};
		int y = {};
	};


	class Input
	{
	public:

		struct Mouse
		{
			Vector2Pos myCurrentPos;
			Vector2Pos myOldPos;
			Vector2Pos myDeltaPos;
			
		};

		bool IsKeyPressed(const int aKeyCode) const;
		bool IsKeyReleased(const int aKeyCode) const;
		bool IsKeyDown(const int aKeyCode) const;
		bool IsMouseButtonPressed(const int aKeyCode) const;
		bool IsMouseButtonDown(const int aKeyCode) const;
		bool IsMouseButtonReleased(const int aKeyCode) const;
		bool GetMousePosition(UINT message);


		int  GetKey(const WPARAM aKeyCode) const;

		bool UpdateEvents(UINT message, WPARAM wParam, LPARAM lParam);
		private:
			Mouse myMouse;
		
			const int myKeyMax = 255;
			std::array<bool, 255>myCurrentKey;
			std::array<bool, 255>myOldKey;
			std::array<bool, 255>myMouseKey;
			std::array<bool, 255>myOldMouseKey;
			
	};



}
