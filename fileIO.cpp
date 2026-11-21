#include <string>
#include "global.h"
#include <iostream>
#include <fstream>
#include "codeLine.h"

void save(){
    
    if(fileName == "none"){
    
        std::cout << "\nEnter file name: ";
        std::cin >> fileName;
        
    }
    
    std::ofstream file(fileName);
            
    if(!file.is_open()){
        std::cout << "\n\033[31mError opening file\033[0m\n";
        return;
    }
    
    for(size_t i = 0; i < commands.size(); i++){
        file << commands[i] << "\n";
    }
    
    std::cout << "\nFile saved successfully\n";
    
}