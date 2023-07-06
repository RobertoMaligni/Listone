//
// Created by samuele on 30/06/23.
//

#include "User.h"
#include "ListFactory.h"
#include "Exceptions/ListNotFound.h"

#include <utility>


User::User(int userId, std::string userName, std::string password) : userID(userId), userName(std::move(userName)),
                                                                     password(std::move(password)) {
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

void User::listUpdate( std::string& listName, std::string &itemName, int quantity) {
    ListFactory factory;
    buffer.push_back(factory.createListUpdate(listName, itemName, quantity));
}

void User::listUpdate(int listID, std::string &itemName, int quantity) {
    ListFactory factory;
    buffer.push_back(factory.createListUpdate(listID, itemName, quantity));
}

void User::notifyObservers() const{
    for(auto update : buffer) {
        for (auto itr : lists) {
            itr->update(update->getListId(),update->getItemName(),update->getQuantity());
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

void User::createList(std::string &listName) {
    ListFactory factory;
    List* list;
    try {
        list = factory.createList(listName);
    }catch(ListNotFound& e){
        list = factory.createList(this,listName);
    }
    lists.push_back(list);
}
