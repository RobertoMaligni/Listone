//
// Created by samuele on 30/06/23.
//

#ifndef LISTONE_USER_H
#define LISTONE_USER_H


#include <string>
#include <list>
#include "Subject.h"
#include "Exceptions/ApplicationException.h"
#include "List.h"
#include <utility>

//TODO
class User {
public:
    User(int userId, const std::string& userName, const std::string& password);
    User(User& user);
    ~User();

    void createList(const std::string& listName);
    int getUserId() const;
    std::string getUserName() const;
    std::string toString() const;

private:
    void loadUserLists();

    int userID;
    std::string userName;
    std::string password;

    std::list<List> ownedLists;
    std::list<List> coopLists;
};


#endif //LISTONE_USER_H
