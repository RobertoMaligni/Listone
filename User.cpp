//
// Created by samuele on 30/06/23.
//

#include "User.h"
#include "FileHandlers/ListHandler.h"
#include <utility>


User::User(int userId, const std::string userName, const std::string password) : userID(userId), userName(userName),
                                                                     password(password) {
    this->loadUserLists();
}

User::~User() {
    for(auto& it : lists){
        delete it;
    }
}

void User::listUpdate( const std::string& listName, const std::string &itemName, int quantity) {
    ListHandler factory;
    buffer.push_back(factory.createListUpdate(listName, itemName, quantity));
}

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
    }catch(ItemNotFound& e){
        list = factory.createList(this,listName);
    }
    list->registerObserver(this);
}

void User::saveLists() {
    //TODO
}

void User::update(const std::string &listName, const std::string &itemName, int quantity) {
    //TODO
}
