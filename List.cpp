//
// Created by samuele on 30/06/23.
//

#include "List.h"

#include <utility>

List::List(User *user, std::string &name) : listName(name){
    user->registerObserver(this);
    ownerIDs.push_back(user->getUserId());
}

List::List(const std::list<int> &ownerIDs, const std::string &listName, const std::list<Item *> &items) : ownerIDs(
        ownerIDs), listName(listName), items(items) {}

List::~List() {
    for(auto& it : items){
        delete it;
    }
}

void List::update(std::string& listName,std::string &itemName, int quantity) {
    if(this->listName == listName) {
        Item *item;
        if (quantity < 0)
            throw std::runtime_error("Quantity in Item cannot be < 0");
        try {
            item = findItem(itemName);
            item->setQuantity(quantity);
            //TODO specify
        } catch (std::exception &e) {
            ItemFactory factory;
            item = factory.createItem(itemName);
            item->setQuantity(quantity);
            items.push_back(item);
        }
    }
}

Item* List::findItem(const Item &item) const{
    auto findIter = std::find(items.begin(), items.end(), &item);
    if(findIter == items.end()){
        throw ItemNotFound(item.getName());
    }
    return *findIter;
}

Item* List::findItem(const std::string& itemName) const{
    auto findIter = items.cend();
    for(auto it = items.cbegin(); it != items.cend(); it++){
        if((*it)->getName() == itemName){
            findIter = it;
            it = items.cend();
        }
    }
    if(findIter == items.end()){
        throw ItemNotFound(itemName);
    }
    return *findIter;
}

const std::string &List::getName() const {
    return listName;
}

const std::list<Item *> &List::getItems() const {
    return items;
}

