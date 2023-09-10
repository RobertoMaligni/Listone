//
// Created by samuele on 05/07/23.
//

#ifndef LISTONE_LISTHANDLER_H
#define LISTONE_LISTHANDLER_H


#include <list>
#include "FileHandler.h"
#include "UserHandler.h"
#include "../List.h"
#include "../User.h"

//TODO ListHandler is an Observer???
class ListHandler : public FileHandler{
public:
    ListHandler();
    ~ListHandler() override;

    void saveList(List& list);

    List* loadListByName(const std::string& listName, const std::string& username);
    std::list<List>& loadListsOwnedByUser(const std::string& username);
    std::list<List>& loadListsNonOwnedByUser(int userID,const std::string& username);

    List* createList(const std::string& listName, User* user);

private:
    List* loadListByPath(const std::string& path);

    std::list<std::string> getUserOwnedListPaths(const std::string& username);
    std::list<std::string> getNonUserOwnedListPaths(int userID, const std::string& username);
    std::list<std::string> getAllListPaths();

};


#endif //LISTONE_LISTHANDLER_H
