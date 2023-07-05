//
// Created by samuele on 30/06/23.
//

#ifndef LISTONE_USER_H
#define LISTONE_USER_H


#include <string>
#include <list>
#include "Subject.h"

class User : public Subject {
public:
    User(int userId, std::string userName, std::string password);
    ~User() override;

    void registerObserver(Observer *o) override;
    void removeObserver(Observer *o) override;
    void notifyObservers() override;
    void setListChange(std::string listName,std::string& itemName, int quantity);
    int getUserId() const;
    std::string toString() const;

private:
    struct NewItem{
        std::string listName;
        std::string& itemName;
        int quantity;
    };

    int userID;
    std::string userName;
    std::string password;
    std::list<NewItem> changes;
    std::list<Observer*> lists;
};


#endif //LISTONE_USER_H
