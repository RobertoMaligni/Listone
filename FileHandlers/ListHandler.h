//
// Created by samuele on 05/07/23.
//

#ifndef LISTONE_LISTHANDLER_H
#define LISTONE_LISTHANDLER_H


#include "FileHandler.h"
#include "../List.h"

class ListHandler : public FileHandler{
public:
    List* loadList(const std::string& listName);
    List* createList( User* user,const std::string& listName);
    ~ListHandler() override;
private:
    const std::string path = "../Files/";
};


#endif //LISTONE_LISTHANDLER_H
