#include <iostream>
#include <vector>
#include <conio.h>
#include <string>
#include <cmath>
#include <windows.h>
#include "cursor.h"
#include "console.h"
#include "codeLine.h"
#include "read.h"
#include "global.h"
#include "SyntaxHighlighting.h"


void writeIDE(){
    
    system("cls");
    
    int maxSize = std::log10(commands.size()+1)+1;
    
    for(int i = 0; i < maxSize; i++){
        std::cout << " ";
    }
    
    std::cout << " "<< fileName << " | Press ESC for functions " << "\n";
    
    for(int i = 0; i < maxSize; i++){
        std::cout << " ";
    }
    
    
    std::cout << " ┌──────────────────────────────────" << "\n";

    
    
    for(size_t i = topLine; i < getEnd(); i++){
        
        std::cout << i+1;
    
        for(size_t j = 0; j < maxSize - (std::log10(i+1)+1); j++){
            std::cout << " ";
        }
        std::cout << " │ ";
        
        std::cout << highlightLine(commands[i]) << "\n";
        
    }
    
    
        
}



void writeLine(){
    std::cout << "\033[2K\r";
    int maxSize = std::log10(commands.size()+1)+1;
    static int oldSize = 1;
    //int maxSize = std::log10(commands.size())+1;
    
    if(maxSize != oldSize){
        oldSize = maxSize;
        writeIDE();
        
        int up = getEnd() - cursorPos.y;
        std::cout << "\033[" << up << "A\r\033[2K";
    }
        
    
    
    std::cout << cursorPos.y+1;
    
    for(int j = 0; j < maxSize - (std::log10(cursorPos.y+1)+1); j++){
        std::cout << " ";
    }
    
    
    std::cout << " │ ";
    
    std::cout << highlightLine(commands[cursorPos.y]);
    
    
    
}



void drawCommands(){
    if(!draw_ideCommands.empty()){
        std::cout << draw_ideCommands;
    }
    
}