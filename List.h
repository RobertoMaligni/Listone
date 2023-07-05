//
// Created by samuele on 30/06/23.
//

#ifndef LISTONE_LIST_H
#define LISTONE_LIST_H

/**
 * TODO: find non redundant way to link lists to users
 *
 * */

#include <list>
#include <algorithm>
#include "Item.h"
#include "Observer.h"
#include "Subject.h"
#include "ItemFactory.h"
#include "User.h"


class List : public Observer{
public:
    List(User* user, std::string& name);
    ~List() override;

    void update(std::string &itemName, int quantity) override;
    const std::string &getName() const;
    int getOwnerId() const;

private:
    Item* findItem(const Item& item) const;
    Item* findItem(const std::string& itemName) const;

    int ownerID;
    int listID;
    std::string name;
    std::list<Item*> items;
};


#endif //LISTONE_LIST_H
