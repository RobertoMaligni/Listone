//
// Created by samuele on 30/06/23.
//

#include "User.h"
#include "FileHandlers/ListHandler.h"


User::User(int userId, const std::string& userName, const std::string& password) : userID(userId), userName(userName),
                                                                     password(password) {
    this->loadUserLists();
}

User::User(User &user) {
    this->userID = user.getUserId();
    this->userName = user.getUserName();
    this->password = user.password;
    this->ownedLists = user.ownedLists;
    this->coopLists = user.coopLists;
}

User::~User() {}


int User::getUserId() const {
    return userID;
}

std::string User::toString() const{
    return std::to_string(userID) + ";" + userName + ";" + password + ";" ;
}

void User::loadUserLists() {
    ListHandler handler;
    ownedLists = handler.loadListsOwnedByUser(userName);
    coopLists = handler.loadListsNonOwnedByUser(userID,userName);
}

void User::createList(const std::string &listName) {
    ListHandler factory;
    List* list;
    /*try {
        list = factory.loadListsOwnedByUser(listName);
    }catch(ApplicationException& e){
        switch(e.getErrorType()){
            case ApplicationException::ErrorType::MissingSaveFiles:
                list = factory.createList(this,listName);
                break;
            default:
                throw ApplicationException(ApplicationException::ErrorType::RunTime);
        }
    }
    //list->registerObserver(this);*/
}

std::string User::getUserName() const {
    return userName;
}
