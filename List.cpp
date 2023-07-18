//
// Created by samuele on 30/06/23.
//

#include "List.h"
#include "Exceptions/GenericFileError.h"

#include <utility>

List::List( User* user, const std::string &name) : listName(name){
    if(user == nullptr){
        throw std::runtime_error("User not passed");
    }
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

void List::update( const std::string& listName, const std::string &itemName, int quantity) {
    if (quantity < 0)
        throw std::runtime_error("Quantity in Item cannot be < 0");
    if(this->listName == listName) {
        Item *item;
        try {
            item = findItem(itemName);
            item->setQuantity(quantity);
        } catch (GenericFileError& e) {
            InventoryHandler factory;
            item = factory.loadItem(itemName);
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

void List::registerObserver(Observer *o) {
//TODO
}

void List::removeObserver(Observer *o) {
//TODO
}

void List::notifyObservers() const {
//TODO
}

const std::list<Item> List::getUnCheckedItems() const {
    //TODO
    return std::list<Item>();
}

