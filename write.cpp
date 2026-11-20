#include <iostream>
#include <vector>
#include <conio.h>
#include <string>
#include <cmath>
#include <windows.h>
#include "cursor.h"
#include "codeLine.h"
#include "read.h"
#include "global.h"


void writeIDE(){
    int maxSize = std::log10(commands.size())+1;
    
    for(int i = 0; i < maxSize; i++){
        std::cout << " ";
    }
    
    std::cout << " "<< fileName << " | Premi ESC per funzioni " << "\n";
    
    for(int i = 0; i < maxSize; i++){
        std::cout << " ";
    }
    
    
    std::cout << "┌──────────────────────────────────" << "\n";
    
    for(int i = 0; i < commands.size(); i++){
        std::cout << i+1;
        
        for(int j = 0; j < maxSize - (std::log10(i+1)+1); j++){
            std::cout << " ";
        }
        std::cout << "│ ";
        
        if(!(cursorPos.y == i)){
            std::cout << commands[i] << "\033[K" << "\n";
        }else{
            for(int j = 0; j < commands[i].size()+1; j++){
                if(i == cursorPos.y && j == cursorPos.x){
                
                    std::cout << "█";
                
                }else{
                    std::cout << commands[i][j];
                }
                    
            }
            
            std::cout << "\033[K" << "\n";
        }
        
    }
        
}

void drawCommands(){
    if(!draw_ideCommands.empty()){
        std::cout << draw_ideCommands << "\033[K";
    }
    
}