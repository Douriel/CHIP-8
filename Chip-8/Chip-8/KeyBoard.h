#pragma once
#include "SDL.h"
#include <iostream>

class KeyBoard
{
public:
	KeyBoard();
	~KeyBoard();
	void pressKey(uint8_t key);
	void releaseKey(uint8_t key);
	bool isKeyPressed(uint8_t key);

private:
	bool keys[16];
};

