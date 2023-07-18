//
// Created by samuele on 01/07/23.
//

#ifndef LISTONE_INVENTORYHANDLER_H
#define LISTONE_INVENTORYHANDLER_H

#include "../Item.h"
#include "FileHandler.h"

class InventoryHandler : public FileHandler{
public:
    Item* loadItem(const std::string& name);
    ~InventoryHandler() override;
private:
    const std::string path = "../Files/Inventory.txt";
};


#endif //LISTONE_INVENTORYHANDLER_H
