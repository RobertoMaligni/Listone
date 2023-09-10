//
// Created by samuele on 05/07/23.
//

#include "ListHandler.h"

ListHandler::ListHandler() {
    path = "../Files/";
}

ListHandler::~ListHandler() {}

List *ListHandler::createList(const std::string &listName, User *user) {
    //TODO
    std::ifstream* file = this->openFile(path);

    //load list name
    std::string currentListName;
    std::getline(*file,currentListName);
    /*try{
        delete this->openFile(path + listName + ".txt"); //list exists?
        throw std::runtime_error("'" + listName + "' already exists");
    }catch(std::runtime_error& e){
        //list dont exists
        return new List(listName, user->getUserId());;
    }*/
}

List *ListHandler::loadListByName(const std::string &listName, const std::string& username) {
    std::list<std::string> fileNamesPaths = getUserOwnedListPaths(username);
    bool found = false;
    List *list;
    for(auto &path : fileNamesPaths){
        if(!found) {
            list = this->loadListByPath(path);
            if (list->getName() == listName) {
                found = true;
            }else{
                delete list;
                list = nullptr;
            }
        }
    }
    if(list == nullptr)
        throw ApplicationException(ApplicationException::ErrorType::MissingSaveFiles);
    return list;
}

std::list<List>& ListHandler::loadListsOwnedByUser(const std::string &username) {
    std::list<List>* list;
    std::list<std::string> fileNames = this->getUserOwnedListPaths(username);
    for(auto& fileName : fileNames){
        list->push_back(*loadListByPath(fileName));
    }
    return *list;
}

std::list<List>& ListHandler::loadListsNonOwnedByUser(int userID,const std::string &username) {
    std::list<List>* list;
    std::list<std::string> fileNames = this->getNonUserOwnedListPaths(userID,username);
    for(auto& fileName : fileNames){
        list->push_back(*loadListByPath(fileName));
    }
    return *list;
}

List* ListHandler::loadListByPath(const std::string &path) {
    std::ifstream* file = this->openFile(path);

    //load list name
    std::string listName;
    std::getline(*file,listName);

    //load userIDs
    std::string line;
    std::getline(*file,line);
    std::replace(line.begin(), line.end(), ';', ' ');  // replace ';' by ' '
    std::stringstream ss(line);
    std::string token;
    std::list<int> userIDs;
    while (ss >> token){
        userIDs.push_back(std::stoi(token));
    }

    //load items
    std::list<std::shared_ptr<Item>> items;
    while(std::getline(*file,line)){
        std::replace(line.begin(), line.end(), ';', ' ');  // replace ';' by ' '
        ss = std::stringstream(line);
        int i = 0;
        InventoryHandler factory;
        Item* item;
        while (ss >> token){
            switch(i){
                case 0:
                    item = factory.loadItem(token);
                    delete &factory;
                    break;
                case 1:
                    if(token != item->getCategory())
                        throw std::runtime_error(""); //should be impossible
                    break;
                case 2:
                    item->setQuantity(std::stoi(token));
                    break;
                case 3:
                    if(std::stoi(token))
                        item->checkItem(false);
                    else
                        item->checkItem(true);
                    break;
                default:
                    //TODO
                    throw std::runtime_error("");
            }
            i++;
        }
        items.push_back(static_cast<const std::shared_ptr<Item>>(item));
    }
    file->close();
    return new List(listName,userIDs,items);
}

std::list<std::string> ListHandler::getAllListPaths() {
    UserHandler handler;
    std::list<std::string> fileNames;
    for(auto &userName :  handler.getUserNames()){
        fileNames.insert(fileNames.end(),
                         this->getUserOwnedListPaths(userName).begin(),
                         this->getUserOwnedListPaths(userName).end());
    }
    return fileNames;
}

std::list<std::string> ListHandler::getUserOwnedListPaths(const std::string& username) {
    int counter = 1;
    bool finished = false;
    std::list<std::string> fileNames;
    while(!finished){
        std::string fileName = username + "@" + std::to_string(counter++);
        try{
            std::ifstream* file = this->openFile(path + fileName);
            fileNames.push_back(path + fileName);
            file->close();
        }catch(ApplicationException& e){
            finished = true;
        }
    }
    return fileNames;
}

std::list<std::string> ListHandler::getNonUserOwnedListPaths(int userID, const std::string &username) {
    std::list<std::string> fileNames;
    for(auto &path : this->getAllListPaths()){
        if(path.find(username) == std::string::npos){ //parse by the name of the file the ownership
            List* list = this->loadListByPath(path);
            if(list->isUserInCoop(userID)) //if its in the list of ids its valid
                fileNames.push_back(path);
        }
    }
    return fileNames;
}

void ListHandler::saveList(List &list) {
//TODO add way to save
}


