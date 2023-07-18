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
}

List::List(const std::string &listName, const std::list<Item *> &items) : listName(listName), items(items) {}

List::~List() {
    for(auto& it : items){
        delete it;
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

const std::string &List::toString() const{
    //TODO
    return " ";
}

