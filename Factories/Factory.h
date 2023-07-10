//
// Created by samuele on 02/07/23.
//

#ifndef LISTONE_FACTORY_H
#define LISTONE_FACTORY_H


#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "../Exceptions/ItemNotFound.h"

class Factory {
public:
    virtual void printFactory();
    virtual ~Factory() = 0;
    bool isEmpty(std::ifstream& file);
protected:
    std::ifstream* openFile(const std::string& path);
    virtual std::string findProduct(const std::string& name);
    const std::string path;
};

#endif //LISTONE_FACTORY_H
