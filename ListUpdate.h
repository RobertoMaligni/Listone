//
// Created by samuele on 06/07/23.
//

#ifndef LISTONE_LISTUPDATE_H
#define LISTONE_LISTUPDATE_H


#include <string>

class ListUpdate {
public:
    ListUpdate(const std::string &listName, const std::string &itemName, int quantity);

    int getListId() const;
    const std::string &getListName() const;
    const std::string &getItemName() const;
    int getQuantity() const;

private:
    int listID;
    std::string listName;
    std::string itemName;
    int quantity;
};


#endif //LISTONE_LISTUPDATE_H