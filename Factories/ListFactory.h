//
// Created by samuele on 05/07/23.
//

#ifndef LISTONE_LISTFACTORY_H
#define LISTONE_LISTFACTORY_H


#include "Factory.h"
#include "../List.h"

class ListFactory : public Factory{
public:
    List* loadList(const std::string& listName);
    List* createList( User* user,const std::string& listName);
    ListUpdate* createListUpdate(const std::string &listName, const std::string &itemName, int quantity);
    ~ListFactory() override;
private:
    const std::string path = "../Files/";
};


#endif //LISTONE_LISTFACTORY_H
