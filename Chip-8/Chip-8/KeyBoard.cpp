#include "KeyBoard.h"

KeyBoard::KeyBoard()
{
    for (int i = 0; i < 16; ++i) {
        keys[i] = false;
    }
}

KeyBoard::~KeyBoard()
{
}

void KeyBoard::pressKey(uint8_t key) {
    if (key < 16) {
        keys[key] = true;
    }
}

void KeyBoard::releaseKey(uint8_t key) {
    if (key < 16) {
        keys[key] = false;
    }
}

bool KeyBoard::isKeyPressed(uint8_t key) {
    return key < 16 ? keys[key] : false;
}




