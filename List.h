//
// Created by samuele on 30/06/23.
//

#ifndef LISTONE_LIST_H
#define LISTONE_LIST_H

#include <list>
#include <algorithm>
#include "Item.h"
#include "Observer.h"
#include "Subject.h"
#include "Factories/ItemFactory.h"
#include "User.h"


class List : public Observer{
public:
    List(const std::list<int> &ownerIDs, const std::string &listName, const std::list<Item *> &items);
    List(User* user, std::string& name);
    ~List() override;

    void update(std::string& listName,std::string &itemName, int quantity) override;
    const std::string &getName() const;
    const std::list<Item *> &getItems() const;


private:
    Item* findItem(const Item& item) const;
    Item* findItem(const std::string& itemName) const;

    std::list<int> ownerIDs;
    std::string listName;
    std::list<Item*> items;
};


#endif //LISTONE_LIST_H
