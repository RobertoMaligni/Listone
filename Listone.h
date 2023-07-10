//
// Created by samuele on 03/07/23.
//

#ifndef LISTONE_LISTONE_H
#define LISTONE_LISTONE_H

#include <string>
#include "User.h"
#include "Factories/UserFactory.h"
#include "Exceptions/UserNotFound.h"
#include "Exceptions/UserNotLoggedIn.h"

class Listone {
public:
    static Listone* getInstance();
    bool isRunning() const;
    void loginUser(const std::string& userName,const std::string& password);
    void registerUser(const std::string& userName,const std::string& password);
    void logOut();
    void createList(const std::string& name) const;
    void addNonOwnedList(const std::string& listName);
    void updateList(const std::string &listName,const std::string& itemName, int quantity);

private:
    bool isLoggedIn() const;
    Listone();
    Listone(const Listone& rs);
    Listone& operator= (const Listone& rs);

    User* user;
    bool running;
    static Listone* instance;
};

#endif //LISTONE_LISTONE_H
