//
// Created by samuele on 30/06/23.
//

#ifndef LISTONE_LIST_H
#define LISTONE_LIST_H

#include <list>
#include <algorithm>
#include <array>
#include "Item.h"
#include "Observer.h"
#include "Subject.h"
#include "FileHandlers/InventoryHandler.h"
#include "User.h"


class List : public Subject{
public:
    List(const std::list<int> &ownerIDs, const std::string &listName, const std::list<Item *> &items);
    List(User* user, const std::string& name);
    ~List() override;

    void update(const std::string& listName,const std::string &itemName, int quantity) override;
    const std::string &getName() const;



private:
    Item* findItem(const Item& item) const;
    Item* findItem(const std::string& itemName) const;

    std::list<int> ownerIDs;
    std::string listName;
    std::list<Item*> items;
};


#endif //LISTONE_LIST_H
