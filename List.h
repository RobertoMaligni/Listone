//
// Created by samuele on 30/06/23.
//

#ifndef LISTONE_LIST_H
#define LISTONE_LIST_H

#include <list>
#include <algorithm>
#include <array>
#include <memory>
#include "Item.h"
#include "Observer.h"
#include "Subject.h"
#include "FileHandlers/InventoryHandler.h"
#include "User.h"

//TODO
class List : public Subject{
public:
    List(const std::string &listName, const std::list<int>& userIDs, const std::list<std::shared_ptr<Item>> &items);
    List(const std::string &listName, int userID);
    ~List() override;

    void registerObserver(Observer *o) override;
    void removeObserver(Observer *o) override;
    void notifyObservers() const override;

    void addItem(Item& item);
    void checkItem(Item& item) const;

    const std::string &getName() const;
    std::list<std::weak_ptr<Item>> getItems() const;
    std::list<std::weak_ptr<Item>> getUnCheckedItems() const;

    //TODO
    void addCoopUserID(int userID);
    void removeCoopUserID(int userID);
    bool isUserInCoop(int userID);



private:
    std::weak_ptr<Item> findItem(const Item& item) const;
    std::weak_ptr<Item> findItem(const std::string& itemName) const;


    std::string listName;
    std::list<int> userIDs;
    std::list<std::shared_ptr<Item>> items;
    std::list<Observer*> observers;
};


#endif //LISTONE_LIST_H
