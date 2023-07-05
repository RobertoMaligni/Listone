//
// Created by samuele on 02/07/23.
//
#include "AbstractFactory.h"
#include "Exceptions/FileError.h"

void AbstractFactory::printFactory() {
    std::string line;
    std::ifstream inventory(path.c_str());
    if(!inventory.is_open()){
        //TODO specify
        throw std::runtime_error("");
    }
    //find line that has same product
    std::cout << "Content of '" << path << "'" << ":" << std::endl;
    while(std::getline(inventory,line)){
       std::cout << line << std::endl;
    }
}

std::ifstream AbstractFactory::openFile() {
    std::string line;
    std::ifstream file(path.c_str());
    if(!file.is_open()){
        throw FileError(path);
    }
    return file;
}

std::string AbstractFactory::findProduct(std::string &name) {
    std::string line;
    std::ifstream file = AbstractFactory::openFile();
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

AbstractFactory::~AbstractFactory() {}
