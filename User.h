//
// Created by samuele on 30/06/23.
//

#ifndef LISTONE_USER_H
#define LISTONE_USER_H


#include <string>
#include <list>
#include "Subject.h"
#include "ListUpdate.h"

class User : public Observer {
public:
    User(int userId, const std::string userName, const std::string password);
    ~User() override;

    void createList(const std::string& listName);
    void listUpdate( const std::string& listName, const std::string& itemName, int quantity);
    void saveLists();
    int getUserId() const;
    std::string toString() const;

private:
    void loadUserLists();

    int userID;
    std::string userName;
    std::string password;
    std::list<ListUpdate*> buffer;
    std::list<Observer*> lists;
};


#endif //LISTONE_USER_H
