#include <string>
#include "global.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include "codeLine.h"

void compile(std::string nameFile, std::string o){
    
    if(nameFile == o){
        size_t pos = o.find('.');
        
        if(pos == std::string::npos){
            o += "_output";
        }else{
            o.erase(pos);
        }
    }
    
    std::string oCommand = "g++ " + nameFile + " -o " + o;
    
    outputName = o;
    
    system(oCommand.c_str());
}

void run(std::string o){

    std::string oCommand = o;
    system(oCommand.c_str());
    
}
void save(){
    
    if(fileName == "none"){
    
        std::cout << "\nInserire nome del file: ";
        std::cin >> fileName;
        
    }
    
    std::ofstream file(fileName);
            
    if(!file.is_open())return;
    
    for(int i = 0; i < commands.size(); i++){
        file << commands[i] << "\n";
    }
    
}