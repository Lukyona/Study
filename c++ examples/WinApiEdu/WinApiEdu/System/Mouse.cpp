#include "framework.h"
#include "MainWindow.h"
#include "Mouse.h"


//////////////////////////////////////////////////////////
// ������
//////////////////////////////////////////////////////////
Mouse::Mouse()
{
	this->handle = MAIN->GetWindowHandle();
	ZeroMemory(buttonStatus, sizeof(BYTE) * 8);     // Mouse Button ����
	ZeroMemory(buttonPrevStatus, sizeof(BYTE) * 8);     // Mouse Button ����
	ZeroMemory(buttonMap, sizeof(Button) * 8);   // 
	ZeroMemory(startDoubleClickTime, sizeof(DWORD) * 8);    // 
	ZeroMemory(buttonCount, sizeof(int) * 8);      // 

	doubleClickTime = GetDoubleClickTime();  // �ý��� ���� Ŭ���ð�

//	doubleClickTime = 200;

}

Mouse::~Mouse()
{
}
void Mouse::WndProc(UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case   WM_MOUSEMOVE:
		m_Position.x = LOWORD(lParam);
		m_Position.y = HIWORD(lParam);
		break;
	case   WM_MOUSEWHEEL:
		break;
	}
}

void Mouse::Update()
{
	// �ٸ�â���� ���콺�� ���������� ���ϱ� ���ؼ�
		//POINT  pt;
		//GetCursorPos(&pt);
		//ScreenToClient(handle, &pt);


	memcpy(this->buttonPrevStatus, this->buttonStatus, sizeof(BYTE) * 8);

	ZeroMemory(buttonStatus, sizeof(BYTE) * 8);
	ZeroMemory(buttonMap, sizeof(BYTE) * 8);

	// button status --> // 0x8000  ������ �������� ���� ȣ�� �������� ���� ����
	//  3~8����.... modify
	buttonStatus[0] = GetAsyncKeyState(VK_LBUTTON) & 0x8000 ? 1 : 0;
	buttonStatus[1] = GetAsyncKeyState(VK_MBUTTON) & 0x8000 ? 1 : 0;
	buttonStatus[2] = GetAsyncKeyState(VK_RBUTTON) & 0x8000 ? 1 : 0;

	for (UINT i = 0; i < 8; i++)
	{
		BYTE prevStatus = buttonPrevStatus[i];
		BYTE CurrentStatus = buttonStatus[i];

		if (prevStatus == 0 && CurrentStatus == 1)
			buttonMap[i] = Button::Down;
		else if (prevStatus == 1 && CurrentStatus == 0)
			buttonMap[i] = Button::Up;
		else if (prevStatus == 1 && CurrentStatus == 1)
			buttonMap[i] = Button::Press;   // ��������� ������ ����
		else
			buttonMap[i] = Button::None;

	}

	// ����Ŭ��
	UINT currentTime = GetTickCount();
	for (UINT i = 0; i < 8; i++)
	{
		if (buttonMap[i] == Button::Down)
		{
			if (buttonCount[i] == 1)
			{
				if (currentTime - startDoubleClickTime[i] >= doubleClickTime)
					buttonCount[i] = 0;

			}
			buttonCount[i]++;
			if (buttonCount[i] == 1)
				startDoubleClickTime[i] = currentTime;
		}

		if (buttonMap[i] == Button::Up)
		{
			if (buttonCount[i] == 1)
			{
				if (currentTime - startDoubleClickTime[i] >= doubleClickTime)
					buttonCount[i] = 0;

			}

			else if (buttonCount[i] == 2)
			{
				if (currentTime - startDoubleClickTime[i] <= doubleClickTime)
					buttonMap[i] = Button::DoubleClick;
				buttonCount[i] = 0;
			}

		}
	}



}

bool Mouse::Down(UINT button)
{
	// �ٸ�â���� ���콺�� ���������� ���ϱ� ���ؼ�

	HWND hwnd = GetFocus();

	if (hwnd == NULL)
		return false;

	if (hwnd != this->handle)
		return false;

	if (buttonMap[button] == Button::Down)
		return true;
	return false;
}

bool Mouse::Up(UINT button)
{
	return buttonMap[button] == Button::Up;
}

bool Mouse::Press(UINT button)
{
	return buttonMap[button] == Button::Press;
}

bool Mouse::DoubleClick(UINT button)
{
	return buttonMap[button] == Button::DoubleClick;
}