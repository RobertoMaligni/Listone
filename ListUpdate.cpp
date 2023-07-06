//
// Created by samuele on 06/07/23.
//

#include "ListUpdate.h"

ListUpdate::ListUpdate(int listId, const std::string &listName, std::string &itemName, int quantity) : listID(listId),
                                                                                                       listName(
                                                                                                               listName),
                                                                                                       itemName(
                                                                                                               itemName),
                                                                                                       quantity(
                                                                                                               quantity) {}

ListUpdate::ListUpdate(int listId, std::string &itemName, int quantity) : listID(listId), itemName(itemName),
                                                                          quantity(quantity) {}

ListUpdate::ListUpdate(const std::string &listName, std::string &itemName, int quantity) : listName(listName),
                                                                                           itemName(itemName),
                                                                                           quantity(quantity) {}

int ListUpdate::getListId() const {
    return listID;
}

const std::string &ListUpdate::getListName() const {
    return listName;
}

std::string &ListUpdate::getItemName() const {
    return itemName;
}

int ListUpdate::getQuantity() const {
    return quantity;
}
