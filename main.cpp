#include <iostream>
#include <vector>
#include <conio.h>
#include <string>
#include <windows.h>
#include "read.h"
#include "write.h"
#include "cursor.h"
#include "codeLine.h"
#include "global.h"
#include "console.h"
#include "fileIO.h"
#include "SyntaxHighlighting.h"

ideStatus status = IDEcommands;

int main(int argc, char* argv[])
{
    
    SetConsoleOutputCP(CP_UTF8);
	system("cls");
    
    initColors();
    
    if(argc >= 2){
        openFile(argv[1]);
        
    }
    
    bool edit = true;
    
    void SetCursor();
    
    //std::cout << "\033[?25l";
    
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTitleA("INIDE");
    while(edit){
        
        
        
        //system("cls");
        int gutter = std::to_string(commands.size()).size() + 3;
        
        //std:: cout << "\033[J";
        //std::getline(std::cin, line);
        
        //cursorPos.x = getCursorPosition().X;
        //cursorPos.y = getCursorPosition().Y;
        
        switch(status){
            case ideStatus::inIDE:
            
                SetConsoleTitleA(("INIDE - " + fileName).c_str());
            
                SetConsoleCursorPosition(h, { (SHORT)(cursorPos.x + gutter), (SHORT)(cursorPos.y + 2) });
                //writeIDE();
                updateinIDE();
                break;
            case ideStatus::IDEcommands:
                
                SetConsoleTitleA("INIDE - functions");
                
                SetConsoleCursorPosition(h, { 0, 0});
                
                drawCommands();
                update_ideCommands();
                break;
            case ideStatus::IDEconsole:
                SetConsoleTitleA("INIDE - console");
                console();
                break;

        }
        
        
        //std:: cout << "\033[J";
        
        //std::cout << "Size: " << commands[cursorPos.y].size() << "\n";
        //std::cout << "Pos Y: " << cursorPos.y << "\n";
        //std::cout << "Pos X: " << cursorPos.x << "\n";

        //y = command.size();
        
    }
    
    
	return 0;
}