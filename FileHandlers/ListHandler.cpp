//
// Created by samuele on 05/07/23.
//

#include "ListHandler.h"

ListHandler::ListHandler() {
    path = "../Files/";
}

ListHandler::~ListHandler() {}

List *ListHandler::loadList(const std::string &listName, const std::string& username) {
    //TODO
    return loadListByPath(path + username + "@" + listName + ".txt");
}

List *ListHandler::createList(const std::string &listName, User *user) {
    //TODO
    try {
        delete this->openFile(path + listName + ".txt"); //list exists?
        throw std::runtime_error("'" + listName + "' already exists");
    }catch(std::runtime_error& e){
        //list dont exists
        return new List(listName, user->getUserId());;
    }
}
//TODO
std::list<List> ListHandler::loadList(const std::string &username) {
    std::list<List> list;
    int counter = 1;
    bool finished = false;
    std::list<std::string> fileNames;
    while(!finished){
        std::string fileName = username + "@" + std::to_string(counter);
        try{
            std::ifstream* file = this->openFile(path + fileName);
            fileNames.push_back(path + fileName);
            file->close();
        }catch(ApplicationException& e){
            finished = true;
        }
    }
    for(auto& fileName : fileNames){
        std::ifstream* file = this->openFile(fileName);

    }
    return list;
}

List *ListHandler::loadListByPath(const std::string &path) {
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
                    throw std::runtime_error("");
            }
            i++;
        }
        items.push_back(static_cast<const std::shared_ptr<Item>>(item));
    }
    return new List(listName,userIDs,items);
}

