#include "Input.h"
#include "windows.h"
#include "winuser.h"
#include "wincon.h"
/* https://stackoverflow.com/questions/9326364/how-to-get-direct-keyboard-input-in-c  source */
int Getkey() {

    while (true) 
	{
        for (int i = 1; i < 255; ++i) {
            // The bitwise and selects the function behavior (look at doc)
            if (GetAsyncKeyState(i) & 0x07)
                return i;

        }

        Sleep(250);
    }
}
bool CommonUtilities::Input::IsKeyDown(const int aKeyCode) const
{
	return false;
}

bool CommonUtilities::Input::IsKeyPressed(const int aKeyCode) const
{
	return false;
}

bool CommonUtilities::Input::IsKeyReleased(const int aKeyCode) const
{
	return false;
}

bool CommonUtilities::Input::IsMouseButtonDown(const int aKeyCode) const
{
	return false;
}

bool CommonUtilities::Input::IsMouseButtonPressed(const int aKeyCode) const
{
	return false;
}

bool CommonUtilities::Input::IsMouseButtonReleased(const int aKeyCode) const
{
	return false;
}

POINT CommonUtilities::Input::GetMousePosition() const
{
 // if (point =< vector.x)(point = vector.x/*screensize.x/*)
	 // if (point =< vector.y)(point = vector.y/*screensize.y/*)
	return POINT();
}

bool CommonUtilities::Input::UpdateEvents(UINT message, WPARAM wParam, LPARAM lParam)
{
	return false;
}
