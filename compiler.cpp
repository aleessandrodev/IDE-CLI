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
        
        std::cout << "ATTENZIONE: il seguente file ha estensione '." + obtainExtansion(nameFile) + "' (" + extensionFile.at(obtainExtansion(nameFile)) + ")\n";
        std::cout << "Lo vuoi compilare ugualmente? [Y/N] ";
        
        while(true){
            char a;
            std::cin >> a;
            
            if(a == 'n' || a == 'N') return;
            if(a == 'y' || a == 'Y') break;
        }
        
    }
        
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
    std::string extension = obtainExtansion(o);
    std::string oCommand = "";
    
    if(extension == "none"){
        oCommand = o;
    }else if(extension == "py"){
        oCommand = "python " + o;
    }
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