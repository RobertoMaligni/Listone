//
// Created by samuele on 30/06/23.
//

#include "User.h"

#include <utility>


User::User(int userId, std::string userName, std::string password) : userID(userId), userName(std::move(userName)),
                                                                     password(std::move(password)) {}

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

void User::setListChange(std::string listName, std::string &itemName, int quantity) {
//TODO add to list the item to change after some controls
}

void User::notifyObservers() {
    //TODO use changes to update lists
    for( auto itr = lists.begin(); lists.end() != itr; ++itr) {
        //TODO (*itr)->update();
    }
}

int User::getUserId() const {
    return userID;
}

std::string User::toString() const{
    return std::to_string(userID) + ";" + userName + ";" + password + ";" ;
}
