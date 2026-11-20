#pragma once
#include <windows.h>

struct Vector2{
    int x;
    int y;
};


extern Vector2 cursorPos;

COORD getCursorPosition();

void SetCursor();