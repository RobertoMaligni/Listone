//
// Created by samuele on 30/06/23.
//

#include "User.h"
#include "Factories/ListFactory.h"
#include "Exceptions/ListNotFound.h"

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

void User::registerObserver(Observer *o) {
    lists.push_back(o);
}

void User::removeObserver(Observer *o) {
    lists.remove(o);
}

void User::listUpdate( const std::string& listName, const std::string &itemName, int quantity) {
    ListFactory factory;
    buffer.push_back(factory.createListUpdate(listName, itemName, quantity));
}

void User::notifyObservers() const{
    for(auto update : buffer) {
        for (auto itr : lists) {
            itr->update(const_cast<std::string &>(update->getListName()),
                        const_cast<std::string &>(update->getItemName()), update->getQuantity());
        }
        delete update;
    }
}

int User::getUserId() const {
    return userID;
}

std::string User::toString() const{
    return std::to_string(userID) + ";" + userName + ";" + password + ";" ;
}

void User::loadUserLists() {
    ListFactory factory;
    //TODO
}

void User::createList(const std::string &listName) {
    ListFactory factory;
    List* list;
    try {
        list = factory.loadList(listName);
    }catch(ListNotFound& e){
        list = factory.createList(this,listName);
    }
    lists.push_back(list);
}

void User::saveLists() {
    //TODO
}
