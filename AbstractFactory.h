//
// Created by samuele on 02/07/23.
//

#ifndef LISTONE_ABSTRACTFACTORY_H
#define LISTONE_ABSTRACTFACTORY_H


#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Exceptions/ItemNotFound.h"
#include "AbstractProduct.h"

class AbstractFactory {
public:
    virtual AbstractProduct* createProduct(std::string& name) = 0;
    virtual AbstractProduct* createProduct(AbstractProduct* product, std::string& name) = 0;
    virtual void printFactory();
    virtual ~AbstractFactory();
protected:
    std::ifstream openFile();
    virtual std::string findProduct(std::string& name);
    const std::string path;
};

#endif //LISTONE_ABSTRACTFACTORY_H
