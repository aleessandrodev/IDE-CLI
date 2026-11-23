#include <conio.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "read.h"
#include "global.h"

void console(){
    
    std::string c;
    std::getline(std::cin, c);
    
    if(c == "exit"){
        status = ideStatus::IDEcommands;
        system("cls");
        return;
    }
    
    system(c.c_str());
    
}

int getConsoleRows(){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Bottom - csbi.srWindow.Top+1;
    
}