//
// Created by samuele on 03/07/23.
//

#ifndef LISTONE_LISTONE_H
#define LISTONE_LISTONE_H
//TODO application class

#include <string>
#include "User.h"

class Listone {
public:
    static Listone* getInstance();
    bool isRunning() const;
    void loginUser(std::string& userName, const std::string& password) const;
    void logOut();
    void createList(std::string& name) const;
    void addNonOwnedList(int listID);
    void updateList(int listID,std::string& itemName, int quantity);

private:
    Listone();
    Listone(const Listone& rs);
    Listone& operator= (const Listone& rs);

    User* user;
    bool running;
    static Listone* instance;
};

#endif //LISTONE_LISTONE_H
