//
// Created by samuele on 30/06/23.
//

#ifndef LISTONE_USER_H
#define LISTONE_USER_H


#include <string>
#include <list>
#include "Subject.h"
#include "AbstractProduct.h"

class User : public Subject , public AbstractProduct{
public:

    User(int userId, std::string userName, std::string password);
    ~User() override;

    void registerObserver(Observer *o) override;
    void removeObserver(Observer *o) override;
    int getUserId() const;
    std::string toString() const;

private:
    void notifyObservers() override;

    int userID;
    std::string userName;
    std::string password;
    std::list<Observer*> lists;
};


#endif //LISTONE_USER_H
