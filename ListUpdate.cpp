//
// Created by samuele on 06/07/23.
//

#include "ListUpdate.h"

ListUpdate::ListUpdate(const std::string &listName, const std::string &itemName, int quantity) : listName(listName),
                                                                                           itemName(itemName),
                                                                                           quantity(quantity) {}

int ListUpdate::getListId() const {
    return listID;
}

const std::string &ListUpdate::getListName() const {
    return listName;
}

const std::string &ListUpdate::getItemName() const {
    return itemName;
}

int ListUpdate::getQuantity() const {
    return quantity;
}
