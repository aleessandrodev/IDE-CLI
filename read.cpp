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
#include "runner.h"
#include "write.h"
#include "fileIO.h"


void updateinIDE(){
        
        int ch = _getch();
    
        if(ch == 13){
            
            std::string line = commands[cursorPos.y].substr(cursorPos.x);
            commands[cursorPos.y].erase(cursorPos.x);

            commands.insert(commands.begin() + cursorPos.y + 1, line);

            cursorPos.y++;
            cursorPos.x = 0;
            updateScroll();
            writeIDE();

            int up = getEnd() - cursorPos.y;
            std::cout << "\033[" << up << "A";

            writeLine();
        }else if(ch == 8){
            
            if(cursorPos.x > 0){
                commands[cursorPos.y].erase(cursorPos.x-1, 1);
                
                //std::cout << "\b \b";
                if(cursorPos.x > 0) cursorPos.x--;
                updateScroll();
                writeLine();
            }else{
                if(cursorPos.y != 0){
                    if(cursorPos.y < commands.size()){
                        
                        int posX = commands[cursorPos.y-1].size();
                        
                        commands[cursorPos.y-1] += commands[cursorPos.y];
                        commands.erase(commands.begin() + cursorPos.y);
                        
                        cursorPos.y--;
                        cursorPos.x = posX;
                        updateScroll();
                        writeIDE();
                        
                    }
                    
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
                        if(cursorPos.x > (int)commands[cursorPos.y].size()) cursorPos.x = commands[cursorPos.y].size();
                        if(updateScroll()) writeIDE();
                    }

                    break;
                case 80: //GIU
                    if(cursorPos.y < (int)commands.size()-1){
                        cursorPos.y++;
                        if(cursorPos.x > (int)commands[cursorPos.y].size()) cursorPos.x = commands[cursorPos.y].size();
                        if(updateScroll()) writeIDE();
                    }
                    break;
                case 75: //SINISTRA
                    if(cursorPos.x > 0) cursorPos.x--;
                    break;
                case 77: //DESTRA
                    if(cursorPos.x < (int)commands[cursorPos.y].size()) cursorPos.x++;
                    break;
                case 83:
                    if(cursorPos.x < (int)commands[cursorPos.y].size()){
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
            _getch();
            system("cls");
            
            
        }else if(command == ":q"){
            exit(0);
        }else if(command == ":b"){
            
            status = ideStatus::inIDE;
            writeIDE();
            
        }else if(command == ":c"){
            std::cout << "\noutput file name: ";
            
                
            
            std::cin >> outputName;
            system("cls");
            //std::cout << "\n";
            save();
            compile(fileName, outputName);
            
            _getch();
            system("cls");
        }else if(command == ":cr"){
            
            std::cout << "\noutput file name: ";
            std::cin >> outputName;
            
            system("cls");
            //std::cout << "\n";
            save();
            compile(fileName, outputName);
            run(outputName);
            
            _getch();
            system("cls");
            
        }else if(command == ":ac"){
            
            system("cls");
            //std::cout << "\n";
            save();
            compile(fileName, fileName);
            
            _getch();
            system("cls");
            
        }else if(command == ":acr"){
            
            system("cls");
            //std::cout << "\n";
            save();
            compile(fileName, fileName);
            run(outputName);
            
            _getch();
            system("cls");
            
        }else if(command == ":r"){
            std::cout << "\nfile name: ";
            std::string n;
            std::cin >> n;
            
            system("cls");
            //std::cout << "\n";
            run(n);
            _getch();
            system("cls");
            
            
        }else if(command == ":ar"){
            
            
            system("cls");
            run(fileName);
            
            _getch();
            system("cls");
            
            
        }else if(command == ":cf"){
            std::cout << "\nfile name (including extension): ";
            std::string n;
            std::cin >> n;
            std::ofstream newfile(n);
            _getch();
            system("cls");
            
        }else if(command == ":of"){
            std::cout << "\nfile name (including extension): ";
            std::cin >> fileName;
            
            
            openFile(fileName);
            
            status = ideStatus::inIDE;
            
            writeIDE();
            
            _getch();
            
            
        }else if(command == ":sfe"){
            std::cout << "\nextension to search: ";
            std::string e;
            std::cin >> e;
            
            std::string c = "dir /b *." + e;
            
            system(c.c_str());
            
            _getch();
            system("cls");
            
        }else if(command == ":sfn"){
            std::cout << "\nname to search: ";
            std::string n;
            std::cin >> n;
            
            std::string c = "dir /b " + n + ".*";
            
            system(c.c_str());
            
            _getch();
            system("cls");
            
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
            std::cout << "\n:goc -> GO IN CONSOLE";
            std::cout << "\n:sfe -> SEARCH FILE BY EXTENSION";
            std::cout << "\n:sfn -> SEARCH FILE BY NAME";
            std::cout << "\n:cf -> CREATE FILE";
            std::cout << "\n:of -> OPEN FILE";
            
            _getch();
            system("cls");
            
        }else{
            
            //draw_ideCommands = "Comando non conosciuto. Digita ':hlp' per aiuto.";
            std::cout << "\n\033[31m\nUnknown command.\033[0m\n";
            std::cout << "Type ':hlp' for help.";
            _getch();
            system("cls");
        }
        
        command = "";
        //_getch();
        
        
        
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