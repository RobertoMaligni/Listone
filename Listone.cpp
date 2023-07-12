//
// Created by samuele on 03/07/23.
//

#include "Listone.h"
#include "Factories/ListFactory.h"

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
void Listone::loginUser(const std::string &userName,const std::string& password) {
    if(userName.empty() || password.empty())
        throw std::runtime_error("Parameters cannot be empty");
    UserFactory factory;
    if(!factory.userExist(userName))
        throw UserNotFound(userName);
    user = factory.loadUser(userName, password);
    std::cout << "Welcome back " << userName << " <3" << std::endl;
}

void Listone::registerUser(const std::string &userName,const std::string &password){
    UserFactory factory;
    if(factory.userExist(userName))
        throw std::runtime_error("User already exists.");
    user = factory.createUser(userName, password);
    std::cout << "Welcome " << userName << " <3" << std::endl;
}

void Listone::logOut() {
    user = nullptr;
    std::cout << "Log out successful " << std::endl;
}

void Listone::createList(const std::string &name) const {
    if(!this->isLoggedIn()) {
        throw UserNotLoggedIn();
    }
    user->createList(name);
}

void Listone::addNonOwnedList(const std::string& listName) {
    ListFactory factory;
    List* list = factory.loadList(listName);
    user->registerObserver(list);
}

void Listone::updateList(const std::string &listName, const std::string &itemName, int quantity) {
    if(!this->isLoggedIn()){
        throw UserNotLoggedIn();
    }
    user->listUpdate(listName,itemName,quantity);
}

bool Listone::isLoggedIn() const{
    return user != nullptr;
}
