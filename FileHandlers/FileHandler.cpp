//
// Created by samuele on 02/07/23.
//
#include "FileHandler.h"
#include "../Exceptions/GenericFileError.h"

void FileHandler::printFactory() {
    //TODO
}

std::ifstream* FileHandler::openFile(const std::string& path) {
    if(path.empty())
        throw std::runtime_error("Parameters cannot be empty");
    auto file = new std::ifstream(path.c_str());
    if(!file->is_open()){
        throw GenericFileError(path);
    }
    return file;
}

std::string FileHandler::findProduct(const std::string &name) {
    if(name.empty())
        throw std::runtime_error("Parameters cannot be empty");
    std::ifstream* file = this->openFile(path);
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

bool FileHandler::parameterExist(int pos, const std::string &string) {
    if(string.empty())
        throw std::runtime_error("Parameters cannot be empty");
    std::string line;
    std::ifstream* file = this->openFile(path);
    if(this->isEmpty(*file)){
        return false;
    }
    bool found = false;
    while(std::getline(*file,line) && !found){
        std::replace(line.begin(), line.end(), ';', ' ');  // replace ';' by ' '
        std::stringstream ss(line);
        std::string token;
        for(int i = 0; i < pos; i++) {
            ss >> token;
        }
        if(token == string)
            found = true;
    }
    return found;
}

bool FileHandler::isEmpty(std::ifstream& file){
    return file.peek() == std::ifstream::traits_type::eof();
}

FileHandler::~FileHandler() {}

