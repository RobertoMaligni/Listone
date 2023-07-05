//
// Created by samuele on 03/07/23.
//

#ifndef LISTONE_USERFACTORY_H
#define LISTONE_USERFACTORY_H


#include "Factory.h"
#include "User.h"

class UserFactory : public Factory{
public:
    User* createUser(std::string& userName, std::string& password);
    User* createUser(int id,std::string& userName, std::string& password);
private:
    const std::string path = "../Files/Users.txt";
};


#endif //LISTONE_USERFACTORY_H
