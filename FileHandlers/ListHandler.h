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
    ~ListHandler() override;
    //TODO add way to save

    List* loadListByName(const std::string& listName, const std::string& username);
    std::list<List> loadListsByUser(const std::string& username);
    std::list<List> loadAllListsByUser(const std::string& username);

    List* createList(const std::string& listName, User* user);
private:
    std::list<std::string> getUserOwnedListPaths(const std::string& username);
    std::list<std::string> getAllUserListPaths(int userID, const std::string& username);
    List* loadListByPath(const std::string& path);

};


#endif //LISTONE_LISTHANDLER_H
