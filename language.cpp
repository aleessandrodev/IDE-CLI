#include <map>
#include <string>

std::map<std::string, std::string> extensionFile = {
    
    {"cpp", "C++"},
    {"py", "python"},
    {"java", "java"},
    {"json", "json"},
    {"js", "javascript"},
    {"html", "HTML"},
    {"htm", "HTML"},
    {"css", "CSS"},
    
    
};

std::string obtainExtansion(std::string fileName){
    
    std::string extension = "none";
    
    size_t pos = fileName.find('.');
    if (pos != std::string::npos) {
        extension = fileName.substr(pos + 1);
    }
    
    return extension;

}