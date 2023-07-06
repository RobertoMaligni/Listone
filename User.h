//
// Created by samuele on 30/06/23.
//

#ifndef LISTONE_USER_H
#define LISTONE_USER_H


#include <string>
#include <list>
#include "Subject.h"
#include "ListUpdate.h"

class User : public Subject {
public:
    User(int userId, std::string userName, std::string password);
    ~User() override;

    void registerObserver(Observer *o) override;
    void removeObserver(Observer *o) override;
    void notifyObservers() const override;
    void createList(std::string& listName);
    void listUpdate( std::string& listName, std::string& itemName, int quantity);
    void listUpdate(int listID, std::string& itemName, int quantity);
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
