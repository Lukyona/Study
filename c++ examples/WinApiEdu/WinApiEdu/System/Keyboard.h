#pragma once
#define   KEYMAX  256
#include  <bitset>
#define   KEYBOARD  Keyboard::GetInstance()
class Keyboard
{
public:
	static Keyboard* GetInstance()
	{
		static Keyboard  instance;
		return &instance;
	}

private:
	Keyboard();
	~Keyboard();

private:
	bitset<KEYMAX> keyUp;
	bitset<KEYMAX> keyDown;
	bitset<KEYMAX> GetKeyUp()   { return keyUp; }
	bitset<KEYMAX> GetKeyDown() { return keyDown; }
	void   SetKeyDown(int key, bool state) { keyDown.set(key, state);}
	void   SetKeyUp(int key, bool state)   { keyUp.set(key, state); }

public:
	bool   Down(int key);
	bool   Up(int key);
	bool   Press(int key);
	void   WindowCallbackKeyDown(int key);
	void   WindowCallbackKeyUp(int key);
};

