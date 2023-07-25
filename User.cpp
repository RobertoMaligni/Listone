//
// Created by samuele on 30/06/23.
//

#include "User.h"
#include "FileHandlers/ListHandler.h"
#include "Exceptions/ApplicationException.h"
#include <utility>


User::User(int userId, const std::string userName, const std::string password) : userID(userId), userName(userName),
                                                                     password(password) {
    this->loadUserLists();
}

User::~User() {}


int User::getUserId() const {
    return userID;
}

std::string User::toString() const{
    return std::to_string(userID) + ";" + userName + ";" + password + ";" ;
}

void User::loadUserLists() {
    ListHandler factory;
    //TODO
}

void User::createList(const std::string &listName) {
    ListHandler factory;
    List* list;
    try {
        list = factory.loadList(listName);
    }catch(ApplicationException& e){
        switch(e.getErrorType()){
            case ApplicationException::ErrorType::MissingSaveFiles:
                list = factory.createList(this,listName);
                break;
            default:
                throw ApplicationException(ApplicationException::ErrorType::RunTime);
        }
    }
    list->registerObserver(this);
}

void User::update(const std::string &listName, const std::string &itemName, int quantity) {
    //TODO
}
