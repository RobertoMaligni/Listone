//
// Created by samuele on 30/06/23.
//

#include "List.h"

List::List(User *user, std::string &name) : name(name){
    user->registerObserver(this);
    ownerID = user->getUserId();
}

List::~List() {
    for(auto& it : items){
        delete it;
    }
}

void List::update(int listID,std::string &itemName, int quantity) {
    if(this->listID == listID) {
        Item *item;
        if (quantity < 0)
            throw std::runtime_error("Quantity in Item cannot be < 0");
        try {
            item = findItem(itemName);
            item->setQuantity(quantity);
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
    return name;
}

int List::getOwnerId() const {
    return ownerID;
}
