
#include "UserHandler.h"

UserHandler::UserHandler() {
    path = "../Files/Users.txt";
}

//get user@1 from file
User *UserHandler::loadUser(const std::string& userName, const std::string& password){
    if(userName.empty() || password.empty())
        throw std::runtime_error("Parameters cannot be empty");
    if(!this->userExist(userName))
        throw ApplicationException(ApplicationException::ErrorType::LoadingFile);
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
                    throw ApplicationException(ApplicationException::ErrorType::RunTime);
                break;
            default:
                throw std::runtime_error("");//should be impossible
        }
    }
    return new User(userID,userName,password);
}

User *UserHandler::loadUser(int userID) {
    std::string line = std::to_string(userID);
    line = this->findProduct(line); //exception may be thrown
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

//create new user@1 runtime
User *UserHandler::createUser(const std::string &userName, const std::string &password){
    if(userName.empty() || password.empty())
        throw std::runtime_error("Parameters cannot be empty");
    try{
        //if it does not throw means user@1 already exist
        std::string line = this->findProduct(userName);
        //TODO specify
        throw std::runtime_error("User already exists");
    }catch(ApplicationException& e){
        //user@1 dont exists
        int userID = getLastUserID() + 1;
        return new User(userID,userName,password);
    }
}

int UserHandler::getLastUserID() {
    std::string line;
    std::ifstream* file = this->openFile(path);
    if(this->isEmpty(*file)){ //No user@1 registered
        return 0;
    }
    while(std::getline(*file,line)){}
    std::replace(line.begin(), line.end(), ';', ' ');  // replace ';' by ' '
    std::stringstream ss(line);
    std::string token;
    ss >> token; //this is the ID
    file->close();
    return std::stoi(token);
}

bool UserHandler::userExist(const std::string &userName) {
    if(userName.empty())
        throw std::runtime_error("Parameters cannot be empty");
    return this->parameterExist(2,userName);;
}

std::list<std::string> UserHandler::getUserNames() {
    std::list<std::string> users;
    std::string line;
    std::ifstream* file = this->openFile(path);
    if(!this->isEmpty(*file)) {
        while (std::getline(*file, line)) {
            std::replace(line.begin(), line.end(), ';', ' ');  // replace ';' by ' '
            std::stringstream ss(line);
            std::string token;
            ss >> token; //ID
            ss >> token; //username
            users.push_back(token);
        }
    }
    file->close();
    return users;
}



