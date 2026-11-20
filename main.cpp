#include <iostream>
#include <vector>
#include <conio.h>
#include <string>
#include <windows.h>
#include "read.h"
#include "write.h"
#include "cursor.h"


ideStatus status = IDEcommands;



int main()
{
    
    SetConsoleOutputCP(CP_UTF8);
	
    
    bool edit = true;
    
    void SetCursor();
    
    //std::cout << "\033[?25l";
    while(edit){
        
        
        
        //system("cls");
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
        std:: cout << "\033[J";
        //std::getline(std::cin, line);
        
        
        
        switch(status){
            case ideStatus::inIDE:
                 
                writeIDE();
                updateinIDE();
                break;
            case ideStatus::IDEcommands:
                
                drawCommands();
                update_ideCommands();
                break;
            
            
        }
        
        
        std:: cout << "\033[J";
        
        /*std::cout << "Size: " << commands[cursorPos.y].size() << "\n";
        std::cout << "Pos Y: " << cursorPos.y << "\n";
        std::cout << "Pos X: " << cursorPos.x << "\n";*/
        
        
        
        
        
        
        //y = command.size();
        
    }
    
    
	return 0;
}
