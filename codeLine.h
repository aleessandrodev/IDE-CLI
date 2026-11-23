#pragma once
#include <vector>
#include <string>

extern std::vector<std::string>commands;
    
extern std::string line;

extern size_t topLine;
extern size_t end;


size_t getEnd();
bool updateScroll();