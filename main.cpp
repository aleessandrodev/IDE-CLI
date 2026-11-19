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
    
    while(edit){
        
        
        
        system("cls");
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
        
        

        
        /*std::cout << "Size: " << commands[cursorPos.y].size() << "\n";
        std::cout << "Pos Y: " << cursorPos.y << "\n";
        std::cout << "Pos X: " << cursorPos.x << "\n";*/
        
        
        
        
        
        
        //y = command.size();
        
    }
    
    
	return 0;
}
