#include <vector>
#include <string>
#include <algorithm>
#include "console.h"
#include "cursor.h"


std::vector<std::string>commands = {""};
    
std::string line = "";

size_t topLine = 0;

size_t getEnd(){
    return std::min(commands.size(), (size_t)(topLine + (getConsoleRows() - 3)));
}

bool updateScroll(){
    int rows = getConsoleRows() - 3; 

    if(cursorPos.y < topLine){
        topLine = cursorPos.y;
        return true;
    
    }else if(cursorPos.y >= topLine + rows){
        topLine = cursorPos.y - rows + 1;
        return true;
    }
        
    return false;
}