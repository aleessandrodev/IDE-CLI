#include <conio.h>
#include <string>
#include <iostream>
#include <cstdlib>
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