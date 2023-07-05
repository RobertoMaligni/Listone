//
// Created by samuele on 03/07/23.
//

#ifndef LISTONE_USERFACTORY_H
#define LISTONE_USERFACTORY_H


#include "AbstractFactory.h"
#include "User.h"

class UserFactory : public AbstractFactory{
public:
    User* createProduct(std::string& userName, std::string& password);
private:
    const std::string path = "../Files/Users.txt";
};


#endif //LISTONE_USERFACTORY_H
