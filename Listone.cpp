//
// Created by samuele on 03/07/23.
//

#include "Listone.h"

//singleton stuff
Listone* Listone::instance = nullptr;

Listone *Listone::getInstance() {
    static Listone theInstance;
    instance = &theInstance;
    return instance;
}

Listone::Listone(const Listone& rs) {
    instance = rs.getInstance();
}

Listone& Listone::operator= (const Listone& rs) {
    if (this != &rs) {
        instance = rs.getInstance();
    }
    return *this;
}


//other stuff
Listone::Listone() {
    running = true;
    user = nullptr;
}

bool Listone::isRunning() const {
    return running;
}

void Listone::loginUser(std::string &userName, const std::string& password) const {
//TODO
}

void Listone::logOut() {
    user = nullptr;
}

void Listone::createList(std::string &name) const {
//TODO
}

void Listone::addNonOwnedList(int listID) {
//TODO
}

void Listone::updateList(int listID, std::string &itemName, int quantity) {
    //TODO

}

void Listone::registerUser(std::string &userName, const std::string &password) {
    //TODO

}

bool Listone::userExists(std::string &userName) {
    return false;
}
