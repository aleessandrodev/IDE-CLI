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
#include "write.h"


void updateinIDE(){
        
        int ch = _getch();
    
        if(ch == 13){
            commands.push_back("");
            cursorPos.y++;
            if(cursorPos.x > commands[cursorPos.y].size()) cursorPos.x = commands[cursorPos.y].size();
            //line.clear();
        }else if(ch == 8){
            if(!commands[cursorPos.y].empty()){
                if(cursorPos.x > 0){
                    commands[cursorPos.y].erase(cursorPos.x-1, 1);
                    
                    //std::cout << "\b \b";
                    if(cursorPos.x > 0) cursorPos.x--;
                    writeLine();
                }
            }
        }else if(ch == 9){
            for(int i = 0; i < 4; i++){
                //commands[cursorPos.y] += "";
                commands[cursorPos.y].insert(cursorPos.x+i, 1, ' ');
                
                
            }
            cursorPos.x += 4;
            writeLine();
            
        }else if(ch == 27){
            status = ideStatus::IDEcommands;
            system("cls");
            
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
                        writeLine();
                    }
                    break;
            }
            
        }else{
            //line += static_cast<char>(ch);
            
            if(ch >= 32 && ch <= 127){
                
                commands[cursorPos.y].insert(cursorPos.x, 1,static_cast<char>(ch));
                cursorPos.x++;
                writeLine();
            
            }
            //std::cout << static_cast<char>(ch);
            
        }    
        
        
        
        
}


std::string draw_ideCommands;
void update_ideCommands(){
    static std::string command = "";
    std::cout << command;
    int ch = _getch();

        if(ch == 27){
            command = "";
            system("cls");
        }

    if(ch == 13){
        std::transform(command.begin(), command.end(), command.begin(), [](unsigned char c){ return std::tolower(c); });
        
        int e = _getch(); 
        if(e == 27){
            command = "";
            system("cls");
        }

        if(command == ":s"){
            
            save();
            
        }else if(command == ":q"){
            exit(0);
        }else if(command == ":b"){
            
            status = ideStatus::inIDE;
            writeIDE();
            
        }else if(command == ":c"){
            std::cout << "\nnome file output: ";
            
                
            
            std::cin >> outputName;
            system("cls");
            //std::cout << "\n";
            save();
            compile(fileName, outputName);
            
            _getch();
        }else if(command == ":cr"){
            
            std::cout << "\nnome file output: ";
            std::cin >> outputName;
            
            system("cls");
            //std::cout << "\n";
            save();
            compile(fileName, outputName);
            run(outputName);
            
            
        }else if(command == ":ac"){
            
            system("cls");
            //std::cout << "\n";
            save();
            compile(fileName, fileName);
            
        }else if(command == ":acr"){
            
            system("cls");
            //std::cout << "\n";
            save();
            compile(fileName, fileName);
            run(outputName);
            
        }else if(command == ":r"){
            std::cout << "\nnome file: ";
            std::string n;
            std::cin >> n;
            
            system("cls");
            //std::cout << "\n";
            run(n);
            _getch();
            
        }else if(command == ":ar"){
            
            
            system("cls");
            run(outputName);
            
            
        }else if(command == ":cf"){
            std::cout << "\nnome file(estensione inclusa): ";
            std::string n;
            std::cin >> n;
            std::ofstream newfile(n);
            _getch();
            
        }else if(command == ":of"){
            std::cout << "\nnome file(estensione inclusa): ";
            std::cin >> fileName;
            std::ifstream file(fileName);
            
            if(!file.is_open()) return;
            
            commands.clear();
            
            
            cursorPos.y = 0;
            cursorPos.x = 0;
            
            
            
            
            std::string riga = "";
            while(std::getline(file, riga)){
                commands.push_back(riga);
            }
            
            if(commands.empty()) commands.push_back("");
            
            status = ideStatus::inIDE;
            
            writeIDE();
            
            _getch();
            
        }else if(command == ":sf"){
            std::cout << "\nnome estensione: ";
            std::string e;
            std::cin >> e;
            
            std::string c = "dir /b *." + e;
            
            system(c.c_str());
            
            _getch();
            
        }else if(command == ":goc"){
            
            status = ideStatus::IDEconsole;
            
            system("cls");
            
            
            
            
        }else if(command == ":hlp"){
            std::cout << "\n:q -> QUIT";
            std::cout << "\n:s -> SAVE";
            std::cout << "\n:b -> BACK";
            std::cout << "\n:c -> COMPILE";
            std::cout << "\n:r -> RUN";
            std::cout << "\n:cr -> COMPILE AND RUN";
            std::cout << "\n:ac -> AUTO COMPILE";
            std::cout << "\n:acr -> AUTO COMPILE AND RUN";
            std::cout << "\n:sf -> SEARCH FILE";
            std::cout << "\n:cf -> CREATE FILE";
            std::cout << "\n:of -> OPEN FILE";
            
            _getch();
            
        }else{
            
            //draw_ideCommands = "Comando non conosciuto. Digita ':hlp' per aiuto.";
            std::cout << "\nComando non conosciuto.\n" << "Digita ':hlp' per aiuto.";
            _getch();
        }
        
        command = "";
        _getch();
        system("cls");
        
        
    }else if(ch == 27){
        
        status = ideStatus::inIDE;
        writeIDE();
        
    }else if(ch ==  8){
        if(!command.empty()){
            command.pop_back();
            std::cout << "\b \b" << std::flush;
            
        }
        
    }else if(ch == 0 || ch == 224){
        
        _getch();
    }else{
        if(ch >= 32 && ch < 127){
            command += static_cast<char>(ch);
        }
    }
    
    

}