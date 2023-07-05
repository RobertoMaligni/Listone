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

void User::notifyObservers() {
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
