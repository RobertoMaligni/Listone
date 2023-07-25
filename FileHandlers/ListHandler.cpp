//
// Created by samuele on 05/07/23.
//

#include "ListHandler.h"
#include "UserHandler.h"

ListHandler::~ListHandler() {}

List *ListHandler::loadList(const std::string &listName) {
    std::ifstream* file = this->openFile(path + listName + ".txt");

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
    std::list<Item *> items;
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
                        item->unCheckItem();
                    else
                        item->checkItem();
                    break;
                default:
                    throw std::runtime_error("");
            }
            i++;
        }
        items.push_back(item);
    }
    return new List(userIDs,listName,items);
}

List *ListHandler::createList(User *user, const std::string &listName) {
    try {
        delete this->openFile(path + listName + ".txt"); //list exists?
        throw std::runtime_error("'" + listName + "' already exists");
    }catch(GenericFileError& e){
        //list dont exists
        return new List(user, listName);;
    }
}

