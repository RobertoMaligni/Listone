//
// Created by samuele on 03/07/23.
//

#include <ctime>
#include "UserFactory.h"
#include "../Exceptions/UserNotFound.h"
#include "../Exceptions/GenericFileError.h"
#include "../Exceptions/IncorrectPassword.h"

//get user from file
User *UserFactory::loadUser(std::string& userName, std::string& password){
    std::string line;
    try{
        line = this->findProduct(userName);
    }catch(GenericFileError& e){
        throw UserNotFound(userName);
    }
    std::stringstream ss(line);
    std::string token;
    int userID;
    for (int i = 0; ss >> token; i++){
        switch(i){
            case 0:
                userID = std::stoi(token);
                break;
            case 1:
                if(token != userName)
                    throw std::runtime_error("");//should be impossible
                break;
            case 2:
                if(token != password)
                    throw IncorrectPassword();
                break;
            default:
                throw std::runtime_error("");//should be impossible
        }
    }
    return new User(userID,userName,password);
}

User *UserFactory::loadUser(int userID) {
    //TODO
    std::string line = std::to_string(userID);
    try{
        line = this->findProduct(line);
    }catch(GenericFileError& e){
        throw UserNotFound(std::to_string(userID));
    }
    std::stringstream ss(line);
    std::string token, userName,password;
    for (int i = 0; ss >> token; i++){
        switch(i){
            case 0:
                if(userID != std::stoi(token))
                    throw std::runtime_error(""); //should be impossible
                break;
            case 1:
                userName = token;
                break;
            case 2:
                password = token;
                break;
            default:
                throw std::runtime_error("");//should be impossible
        }
    }
    return new User(userID,userName,password);
}

//create new user runtime
User *UserFactory::createUser(std::string &userName, std::string &password){
    try{
        //if it does not throw means user already exist
        std::string line = this->findProduct(userName);
        //TODO specify
        throw std::runtime_error("User already exists");
    }catch(GenericFileError& e){
        //user dont exists
        int userID = getLastUserID() + 1;
        return new User(userID,userName,password);
    }
}

int UserFactory::getLastUserID() {
    std::string line;
    std::ifstream* file = this->openFile(path);
    if(this->isEmpty(*file)){ //No user registered
        return 0;
    }
    bool found = false;
    while(std::getline(*file,line)){}
    std::replace(line.begin(), line.end(), ';', ' ');  // replace ';' by ' '
    std::stringstream ss(line);
    std::string token;
    ss >> token; //ID
    return std::stoi(token);
}



