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
		float x = {};
		float y = {};
	};


	class Input
	{
	public:

		struct Mouse
		{
			Vector2Pos myCurrentPos;
			Vector2Pos myOldPos;
			Vector2Pos myPosDelta;

			float currentWheel;
			float previousWheel;
			float deltaWheel;

		};

		bool IsKeyPressed(const int aKeyCode) const;
		bool IsKeyReleased(const int aKeyCode) const;
		bool IsKeyDown(const int aKeyCode) const;
		bool IsMouseButtonPressed(const int aKeyCode) const;
		bool IsMouseButtonDown(const int aKeyCode) const;
		bool IsMouseButtonReleased(const int aKeyCode) const;

		void UpdateMousePosition(UINT message);

		Vector2Pos GetMousePosition() const { return myMouse.myCurrentPos; }
		Vector2Pos GetOldMousePosition() const { return myMouse.myOldPos; }
		Vector2Pos GetMouseDelta() const { return myMouse.myPosDelta; }
		float GetWheelScroll() const
		{
			return myMouse.deltaWheel / 120.0f;
		}
		const int  GetKeyCode(const WPARAM wParam) const;

		bool  IsKeyValid(const WPARAM wParam) const;

		bool UpdateEvents(UINT message, WPARAM wParam, LPARAM lParam);
	private:
		Mouse myMouse;

		const int myKeyMax = 256;
		std::array<bool, 256>myCurrentKey;
		std::array<bool, 256>myOldKey;
		std::array<bool, 256>myStoredKey;
		std::array<bool, 256>myMouseKey;
		std::array<bool, 256>myOldMouseKey;

	};



}
