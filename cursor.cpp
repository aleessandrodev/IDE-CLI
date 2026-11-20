#include "cursor.h"
#include <windows.h>

Vector2 cursorPos;

COORD getCursorPosition() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        return csbi.dwCursorPosition;
    }
    return { -1, -1 };
}



void SetCursor(){
    cursorPos.x = 0;
    cursorPos.y = 0;

}