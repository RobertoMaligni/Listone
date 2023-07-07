//
// Created by samuele on 05/07/23.
//

#include "ListFactory.h"

ListFactory::~ListFactory() {}

List *ListFactory::loadList(std::string &listName) {
    //TODO recover from file
    return nullptr;
}

List *ListFactory::createList(const User *user, std::string &listName) {
    //TODO create at runtime
    return nullptr;
}

ListUpdate *ListFactory::createListUpdate(std::string &listName, std::string &itemName, int quantity) {
    //TODO
    return nullptr;
}

ListUpdate *ListFactory::createListUpdate(int listId, std::string &itemName, int quantity) {
    //TODO
    return nullptr;
}
