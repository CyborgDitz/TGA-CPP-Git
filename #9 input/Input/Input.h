#pragma once
namespace CommonUtilities
{


	class Input
	{ public:
		bool IsKeyDown(const int aKeyCode) const;
		bool IsKeyPressed(const int aKeyCode) const;
		bool IsKeyReleased(const int aKeyCode) const;
		bool IsMouseButtonDown(const int aKeyCode) const;
		bool IsMouseButtonPressed(const int aKeyCode) const;
		bool IsMouseButtonReleased(const int aKeyCode) const;
	//	POINT GetMousePosition() const;
			int Getkey();


		//bool UpdateEvents(UINT message, WPARAM wParam, LPARAM lParam);
		private:

	};

}
