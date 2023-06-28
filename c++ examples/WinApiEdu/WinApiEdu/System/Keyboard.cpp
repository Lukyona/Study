#include  "framework.h"
#include "Keyboard.h"

Keyboard::Keyboard()
{
	for (int i = 0; i < KEYMAX; i++)
	{
		GetKeyUp().set(i, false);
		GetKeyDown().set(i, false);
	}
}

Keyboard::~Keyboard()
{
}
//////////////////////////////////////////////////////////
// 향후: 수정예정
/////////////////////////////////////////////////////////
bool Keyboard::Down(int key)
{
	// 이전에 누른 적 없으면
	if (GetAsyncKeyState(key) & 0x8000)
	{
		if (!GetKeyDown()[key])
		{
			SetKeyDown(key, true);
			return true;
		}
	}
	else
	{
		if (GetKeyDown()[key])
		{
			SetKeyDown(key, false);
			return true;
		}
	}

	return false;
}

bool Keyboard::Up(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)
		SetKeyUp(key, true);
	else
	{
		if (GetKeyUp()[key])
		{
			SetKeyUp(key, false);
			return true;
		}
	}

	return false;
}

bool Keyboard::Press(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)
		return true;
	else
		return false;
}

void Keyboard::WindowCallbackKeyDown(int key)
{
	SetKeyDown(key, true);
}

void Keyboard::WindowCallbackKeyUp(int key)
{
	SetKeyUp(key, true);
}
