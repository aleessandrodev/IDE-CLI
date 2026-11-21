#pragma once
#include <map>
#include <string>

extern std::map<std::string, std::string> extensionFile;
std::string obtainExtansion(std::string fileName);
std::string removeExtension(std::string fileName);