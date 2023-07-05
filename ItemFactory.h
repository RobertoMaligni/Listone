//
// Created by samuele on 01/07/23.
//

#ifndef LISTONE_ITEMFACTORY_H
#define LISTONE_ITEMFACTORY_H

#include "Item.h"
#include "Factory.h"

class ItemFactory : public Factory{
public:
    Item* createProduct(std::string& name);
    ~ItemFactory() override;
private:
    const std::string path = "../Files/Inventory.txt";
};


#endif //LISTONE_ITEMFACTORY_H
