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
    List(const std::string &listName, const std::list<std::shared_ptr<Item>> &items);
    List(User* user, const std::string& name);
    ~List() override;

    void registerObserver(Observer *o) override;
    void removeObserver(Observer *o) override;
    void notifyObservers() const override;
    void addItem(const Item& item);
    void checkItem(const Item& item) const;

    const std::string &getName() const;
    const std::list<std::weak_ptr<Item>> getItems() const;
    const std::list<std::weak_ptr<Item>> getUnCheckedItems() const;


private:
    std::weak_ptr<Item> findItem(const Item& item) const;
    std::weak_ptr<Item> findItem(const std::string& itemName) const;
    const std::string& toString() const;


    std::string listName;
    std::list<std::shared_ptr<Item>> items;
    std::list<Observer*> observers;
};


#endif //LISTONE_LIST_H
