#include <iostream>
#include <vector>
#include <conio.h>
#include <string>
#include <windows.h>
#include "cursor.h"
#include "codeLine.h"
#include "read.h"


void writeIDE(){
    for(int i = 0; i < commands.size(); i++){
        std::cout << i+1 << "| ";
        
        if(!(cursorPos.y == i)){
            std::cout << commands[i] << "\n";
        }else{
            for(int j = 0; j < commands[i].size()+1; j++){
                if(i == cursorPos.y && j == cursorPos.x){
                
                    std::cout << "█";
                
                }else{
                    std::cout << commands[i][j];
                }
                    
            }
            
            std::cout << std::endl;
        }
        
    }
        
}

void drawCommands(){
    if(!draw_ideCommands.empty()){
        std::cout << draw_ideCommands;
    }
    
}