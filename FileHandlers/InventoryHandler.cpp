//
// Created by samuele on 01/07/23.
//

#include "InventoryHandler.h"

InventoryHandler::InventoryHandler() {
    path = "../Files/Inventory.txt";
}

Item* InventoryHandler::loadItem(const std::string &name) {
    std::string line = findProduct(name); //fine if propagate since the main has to handle this exception

    size_t pos = 0;
    std::string token;
    std::string delimiter = ";";
    while ((pos = line.find(delimiter)) != std::string::npos) {
        token = line.substr(0, pos);
        std::cout << token << std::endl;
        line.erase(0, pos + delimiter.length());
    }
    return new Item(name,token);
}

InventoryHandler::~InventoryHandler() {}

