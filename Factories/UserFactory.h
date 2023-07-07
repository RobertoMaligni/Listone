//
// Created by samuele on 03/07/23.
//

#ifndef LISTONE_USERFACTORY_H
#define LISTONE_USERFACTORY_H


#include "Factory.h"
#include "../User.h"

class UserFactory : public Factory{
public:
    User* loadUser(std::string& userName, std::string& password);
    User* loadUser(int userID);
    User* createUser(std::string& userName, std::string& password);
private:
    int getLastUserID();
    const std::string path = "../Files/Users.txt";
};


#endif //LISTONE_USERFACTORY_H
