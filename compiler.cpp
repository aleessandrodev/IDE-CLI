#include <string>
#include "global.h"
#include <cstdlib>

void compile(std::string nameFile, std::string o){
    
    if(nameFile == o) o += "_output";
    
    std::string oCommand = "g++ " + nameFile + " -o " + o;
    
    outputName = o;
    
    system(oCommand.c_str());
}

void run(std::string o){

    std::string oCommand = o;
    system(oCommand.c_str());
    
}