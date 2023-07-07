//
// Created by samuele on 02/07/23.
//
#include "Factory.h"
#include "../Exceptions/FileError.h"

void Factory::printFactory() {
    std::string line;
    std::ifstream inventory(path.c_str());
    if(!inventory.is_open()){
        throw std::runtime_error("Unable to print factory");
    }
    //find line that has same product
    std::cout << "Content of '" << path << "'" << ":" << std::endl;
    while(std::getline(inventory,line)){
       std::cout << line << std::endl;
    }
}

std::ifstream Factory::openFile() {
    std::string line;
    std::ifstream file(path.c_str());
    if(!file.is_open()){
        throw FileError(path);
    }
    return file;
}

std::string Factory::findProduct(std::string &name) {
    std::string line;
    std::ifstream file = Factory::openFile();
    bool found = false;
    while(std::getline(file,line) && !found){
        std::replace(line.begin(), line.end(), ';', ' ');  // replace ';' by ' '
        std::stringstream ss(line);
        std::string token;
        while (ss >> token && !found){
            if(token == name)
                found = true;
        }
    }
    if(!found) {
        throw FileError(path);
    }
    return line;
}

Factory::~Factory() {}
