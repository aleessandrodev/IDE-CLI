#include <string>
#include "global.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include "codeLine.h"
#include "language.h"

void compile(std::string nameFile, std::string o){
    
    fileName = nameFile;
    
    if(obtainExtansion(nameFile) != "cpp"){
        
        std::cout << "\033[31mWARNING\033[0m: the following file has extension '." + obtainExtansion(nameFile) + "' (" + extensionFile.at(obtainExtansion(nameFile)) + ")\n";
        std::cout << "Do you want to compile it anyway? [Y/N] ";
        
        while(true){
            char a;
            std::cin >> a;
            
            if(a == 'n' || a == 'N') return;
            if(a == 'y' || a == 'Y') break;
        }
        
    }
        
    if(nameFile == o){
        if(removeExtension(nameFile) == "none"){
            o += "_output";
        }else{
            o = removeExtension(fileName);
        }
    }
    
    std::string oCommand = "g++ " + nameFile + " -o " + o;
    
    outputName = o;
    
    system(oCommand.c_str());
}

void run(std::string o){
    std::string extension = obtainExtansion(o);
    std::string oCommand = o;
    
    if(extension == "none"){
        oCommand = o;
    }else if(extension == "py"){
        oCommand = "python " + o;
    }else if(extension == "java"){
        oCommand = "javac " + o + "&& java " + removeExtension(o);
    }else{
        oCommand = removeExtension(o);
    }
    
    
    system(oCommand.c_str());
}



