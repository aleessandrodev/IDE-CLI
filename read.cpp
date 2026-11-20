
#include <iostream>
#include <vector>
#include <conio.h>
#include <string>
#include <windows.h>
#include "read.h"
#include "cursor.h"
#include "codeLine.h"
#include "global.h"
#include <algorithm>
#include <cctype>
#include <fstream>
#include "compiler.h"


void updateinIDE(){
        
        int ch = _getch();
    
        if(ch == 13){
            commands.push_back("");
            cursorPos.y++;
            if(cursorPos.x > commands[cursorPos.y].size()) cursorPos.x = commands[cursorPos.y].size();
            //line.clear();
        }else if(ch == 8){
            if(!commands[cursorPos.y].empty()){
                commands[cursorPos.y].erase(cursorPos.x, 1);
                
                //std::cout << "\b \b";
                if(cursorPos.x > 0) cursorPos.x--;
            }
        }else if(ch == 9){
            for(int i = 0; i < 4; i++){
                //commands[cursorPos.y] += "";
                commands[cursorPos.y].insert(cursorPos.x+i, 1, ' ');
                
            }
            cursorPos.x += 4;
            
        }else if(ch == 27){
            status = ideStatus::IDEcommands;
            
            
        }else if(ch == 224 || ch == 0){
            int arrow = _getch();
            
            switch(arrow){
                case 72: //SU
                    if(cursorPos.y > 0){
                        
                        cursorPos.y--;
                        if(cursorPos.x > commands[cursorPos.y].size()) cursorPos.x = commands[cursorPos.y].size();
                    
                    }
                    
                    
                    
                    break;
                case 80: //GIU
                    if(cursorPos.y < commands.size()-1){
                        cursorPos.y++;
                        if(cursorPos.x > commands[cursorPos.y].size()) cursorPos.x = commands[cursorPos.y].size();
                    }
                    break;
                case 75: //SINISTRA
                    if(cursorPos.x > 0) cursorPos.x--;
                    break;
                case 77: //DESTRA
                    if(cursorPos.x < commands[cursorPos.y].size()) cursorPos.x++;
                    break;
                case 83:
                    if(cursorPos.x < commands[cursorPos.y].size()){
                        commands[cursorPos.y].erase(cursorPos.x, 1);
                    }
                    break;
            }
            
        }else{
            //line += static_cast<char>(ch);
            
            commands[cursorPos.y].insert(cursorPos.x, 1,static_cast<char>(ch));
            cursorPos.x++;
            //std::cout << static_cast<char>(ch);
            
        }    
        
        
        
        
}


std::string draw_ideCommands;
void update_ideCommands(){
    static std::string command = "";
    std::cout << command;
    int ch = _getch();

    if(ch == 13){
        std::transform(command.begin(), command.end(), command.begin(), [](unsigned char c){ return std::tolower(c); });
        

        if(command == ":s"){
            
            std::ofstream file(fileName);
            
            if(!file.is_open())return;
            
            for(int i = 0; i < commands.size(); i++){
                file << commands[i] << "\n";
            }
            
        }else if(command == ":q"){
            exit(0);
        }else if(command == ":b"){
            status = ideStatus::inIDE;
        }else if(command == ":c"){
            std::cout << "\nnome file output: " << "\033[K";
            
                
            
            std::cin >> outputName;
            
            compile(fileName, outputName);
            
            _getch();
        }else if(command == ":cr"){
            
            std::cout << "\nnome file output: " << "\033[K";
            std::cin >> outputName;
            
            compile(fileName, outputName);
            run(outputName);
            
            
        }else if(command == ":ac"){
            
            compile(fileName, fileName);
            
        }else if(command == ":acr"){
            
            compile(fileName, fileName);
            run(outputName);
            
        }else if(command == ":r"){
            std::cout << "\nnome file: " << "\033[K";
            std::string n;
            std::cin >> n;
            run(n);
            _getch();
            
        }else if(command == ":ar"){
            
            run(outputName);
            
            
        }else if(command == ":cf"){
            std::cout << "\nnome file(estensione inclusa): " << "\033[K";
            std::string n;
            std::cin >> n;
            std::ofstream newfile(n);
            _getch();
            
        }else if(command == ":of"){
            std::cout << "\nnome file(estensione inclusa): " << "\033[K";
            std::cin >> fileName;
            std::ifstream file(fileName);
            
            if(!file.is_open()) return;
            
            commands.clear();
            cursorPos.y = 0;
            cursorPos.x = 0;
            
            
            commands.push_back("");
            std::string riga = "";
            while(std::getline(file, riga)){
                commands.push_back(riga);
            }
            
            status = ideStatus::inIDE;
            
            _getch();
            //OPEN FILE
        }else if(command == ":hlp"){
            std::cout << "\n:q -> QUIT" << "\033[K";
            std::cout << "\n:s -> SAVE" << "\033[K";
            std::cout << "\n:b -> BACK" << "\033[K";
            std::cout << "\n:c -> COMPILE";
            std::cout << "\n:r -> RUN" << "\033[K";
            std::cout << "\n:cr -> COMPILE AND RUN" << "\033[K";
            std::cout << "\n:ac -> AUTO COMPILE" << "\033[K";
            std::cout << "\n:acr -> AUTO COMPILE AND RUN" << "\033[K";
            std::cout << "\n:cf -> CREATE FILE" << "\033[K";
            std::cout << "\n:of -> OPEN FILE" << "\033[K";
            
            _getch();
            
        }else{
            
            //draw_ideCommands = "Comando non conosciuto. Digita ':hlp' per aiuto.";
            std::cout << "\nComando non conosciuto.\n" << "\033[K" << "Digita ':hlp' per aiuto." << "\033[K";
            _getch();
        }
        command = "";
        
        
        
    }else if(ch ==  8){
        if(!command.empty()){
            command.pop_back();
        }
        
    }else{
        if(ch >= 32 && ch < 127){
            command += static_cast<char>(ch);
        }
    }
    
    

}