//
// Created by samuele on 03/07/23.
//

#include <ctime>
#include "UserHandler.h"
#include "../Exceptions/ApplicationException.h"

//get user from file
User *UserHandler::loadUser(const std::string& userName, const std::string& password){
    if(userName.empty() || password.empty())
        throw std::runtime_error("Parameters cannot be empty");
    if(!this->userExist(userName))
        ApplicationException(ApplicationException::ErrorType::LoadingFile);
    std::string line = this->findProduct(userName);
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
                    ApplicationException(ApplicationException::ErrorType::RunTime);
                break;
            default:
                throw std::runtime_error("");//should be impossible
        }
    }
    return new User(userID,userName,password);
}

User *UserHandler::loadUser(int userID) {
    //TODO
    std::string line = std::to_string(userID);
    try{
        line = this->findProduct(line);
    }catch(GenericFileError& e){
        throw ItemNotFound(std::to_string(userID));
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
User *UserHandler::createUser(const std::string &userName, const std::string &password){
    if(userName.empty() || password.empty())
        throw std::runtime_error("Parameters cannot be empty");
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

int UserHandler::getLastUserID() {
    std::string line;
    std::ifstream* file = this->openFile(path);
    if(this->isEmpty(*file)){ //No user registered
        return 0;
    }
    while(std::getline(*file,line)){}
    std::replace(line.begin(), line.end(), ';', ' ');  // replace ';' by ' '
    std::stringstream ss(line);
    std::string token;
    ss >> token; //ID
    return std::stoi(token);
}

bool UserHandler::userExist(const std::string &userName) {
    if(userName.empty())
        throw std::runtime_error("Parameters cannot be empty");
    return this->parameterExist(2,userName);;
}



