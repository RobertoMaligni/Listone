//
// Created by samuele on 03/07/23.
//

#include "Listone.h"
#include "ListFactory.h"

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
void Listone::loginUser(std::string &userName, std::string& password) {
    UserFactory factory;
    try {
        user = factory.loadUser(userName, password);
        std::cout << "Welcome back " << userName << " <3" << std::endl;
    }catch(UserNotFound& e){
        std::cout << e.what() << std::endl;
    }
}

void Listone::registerUser(std::string &userName, std::string &password){
    UserFactory factory;
    try {
        user = factory.loadUser(userName, password);
    }catch(UserNotFound& e){
        user = factory.loadUser(userName, password);
        std::cout << "Welcome " << userName << " <3" << std::endl;
    }
}

void Listone::logOut() {
    user = nullptr;
    std::cout << "Log out successful " << std::endl;
}

void Listone::createList(std::string &name) const {
    if(!this->isLoggedIn()) {
        throw UserNotLoggedIn();
    }
    user->createList(name);
}

void Listone::addNonOwnedList(std::string& listName) {
    ListFactory factory;
    List* list = factory.createList(listName);
    user->registerObserver(list);
}

void Listone::updateList(int listID, std::string &itemName, int quantity) {
    if(!this->isLoggedIn()){
        throw UserNotLoggedIn();
    }
    user->listUpdate(listID,itemName,quantity);

}

bool Listone::isLoggedIn() const{
    return user != nullptr;
}
