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

List::List(const std::string &listName, const std::list<std::shared_ptr<Item>> &items) : listName(listName), items(items) {}

List::~List() {}

std::weak_ptr<Item> List::findItem(const Item& item) const{
    auto findIter = std::find(items.begin(), items.end(), &item);
    if(findIter == items.end()){
        throw ItemNotFound(item.getName());
    }
    return *findIter;
}

std::weak_ptr<Item> List::findItem(const std::string& itemName) const{
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
    for(auto& user : users){
        user->update();
    }
}

const std::list<std::weak_ptr<Item>> List::getUnCheckedItems() const {
    std::list<std::weak_ptr<Item>> weakItems;
    for(const auto& item : items){
        if(!item->isChecked())
            weakItems.push_back(item);
    }
    return weakItems;
}

const std::list<std::weak_ptr<Item>> List::getItems() const {
    std::list<std::weak_ptr<Item>> weakItems;
    for(const auto& item : items){
        weakItems.push_back(item);
    }
    return weakItems;
}

const std::string &List::toString() const{
    //TODO
    return " ";
}