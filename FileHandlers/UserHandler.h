//
// Created by samuele on 03/07/23.
//

#ifndef LISTONE_USERHANDLER_H
#define LISTONE_USERHANDLER_H


#include "FileHandler.h"
#include "../User.h"

class UserHandler : public FileHandler{
public:
    UserHandler();
    User* loadUser(const std::string& userName, const std::string& password);
    User* loadUser(int userID);
    User* createUser(const std::string& userName, const std::string& password);
    bool userExist(const std::string& userName);
private:
    int getLastUserID();
};


#endif //LISTONE_USERHANDLER_H
