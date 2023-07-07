//
// Created by samuele on 02/07/23.
//
#include "Factory.h"
#include "../Exceptions/GenericFileError.h"

void Factory::printFactory() {
    //TODO
}

std::ifstream* Factory::openFile() {
    auto file = new std::ifstream(path.c_str());
    if(!file->is_open()){
        throw GenericFileError(path);
    }
    return file;
}

std::string Factory::findProduct(std::string &name) {
    std::ifstream* file = this->openFile();
    std::string line;
    bool found = false;
    while(std::getline(*file,line) && !found){
        std::replace(line.begin(), line.end(), ';', ' ');  // replace ';' by ' '
        std::stringstream ss(line);
        std::string token;
        while (ss >> token && !found){
            if(token == name)
                found = true;
        }
    }
    if(!found) {
        throw GenericFileError(path);
    }
    file->close();
    return line;
}

bool Factory::isEmpty(std::ifstream& file){
    return file.peek() == std::ifstream::traits_type::eof();
}

Factory::~Factory() {}

