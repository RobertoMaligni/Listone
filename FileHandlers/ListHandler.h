//
// Created by samuele on 05/07/23.
//

#ifndef LISTONE_LISTHANDLER_H
#define LISTONE_LISTHANDLER_H


#include <list>
#include "FileHandler.h"
#include "../List.h"
#include "../User.h"

class ListHandler : public FileHandler{
public:
    ListHandler();
    List* loadList(const std::string& listName, const std::string& username);
    std::list<List> loadList(const std::string& username);
    List* createList(const std::string& listName, User* user);
    ~ListHandler() override;
private:
    List* loadListByPath(const std::string& path);
};


#endif //LISTONE_LISTHANDLER_H
