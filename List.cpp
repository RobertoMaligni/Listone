//
// Created by samuele on 30/06/23.
//

#include "List.h"
#include "Exceptions/ApplicationException.h"
#include <utility>

List::List(const std::string &listName, const std::list<int>& userIDs, const std::list<std::shared_ptr<Item>> &items) : listName(listName),userIDs(userIDs), items(items) {}

List::List(const std::string &listName, int userID) :  listName(listName){
    userIDs.push_back(userID);
}

List::~List() {}

std::weak_ptr<Item> List::findItem(const Item& item) const{
    //TODO fix
    auto findIter = items.end();//= std::find(items.begin(), items.end(), &item);
    if(findIter == items.end()){
        throw ApplicationException(ApplicationException::ErrorType::RunTime);
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
        throw ApplicationException(ApplicationException::ErrorType::RunTime);
    }
    return *findIter;
}

const std::string &List::getName() const {
    return listName;
}

void List::registerObserver(Observer *o) {
    observers.push_back(o);
}

void List::removeObserver(Observer *o) {
    observers.remove(o);
}

void List::notifyObservers() const {
    for(auto& user : observers){
        //user->update();
    }
}

std::list<std::weak_ptr<Item>> List::getUnCheckedItems() const {
    std::list<std::weak_ptr<Item>> weakItems;
    for(const auto& item : items){
        if(!item->isChecked())
            weakItems.push_back(item);
    }
    return weakItems;
}

std::list<std::weak_ptr<Item>> List::getItems() const {
    std::list<std::weak_ptr<Item>> weakItems;
    for(const auto& item : items){
        weakItems.push_back(item);
    }
    return weakItems;
}

void List::addItem(Item &item) {
    bool found = false;
    for(const auto& current : items){
        if(item == *current && !found) {
            found = true;
            if(item.getQuantity() == current->getQuantity()){
                throw ApplicationException(ApplicationException::ErrorType::CorruptedAppState);
            }
            current->setQuantity(item.getQuantity());
        }
    }
    if(!found){
        items.push_back(std::shared_ptr<Item>(&item));
    }
}

void List::checkItem(Item &item) const {
    bool found = false;
    for(const auto& current : items){
        if(item == *current && !found) {
            found = true;
            if(item.isChecked() && current->isChecked()){
                throw ApplicationException(ApplicationException::ErrorType::CorruptedAppState);
            }
            current->checkItem();
        }
    }
    if(!found){
        throw ApplicationException(ApplicationException::ErrorType::RunTime);
    }
}
