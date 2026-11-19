#pragma once
#include <string>

void updateinIDE();
void update_ideCommands();

extern std::string draw_ideCommands;

enum ideStatus{
    inIDE,
    IDEcommands,
    
};