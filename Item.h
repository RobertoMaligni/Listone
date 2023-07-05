//
// Created by samuele on 30/06/23.
//

#ifndef LISTONE_ITEM_H
#define LISTONE_ITEM_H


#include <string>

class Item {
public:
    Item(std::string& name, std::string&  category,int quantity = 0);
    ~Item() = default;

    bool operator==(const Item &rhs) const;
    bool operator!=(const Item &rhs) const;

    bool isTaken() const;
    void checkItem();
    void unCheckItem();
    const std::string &getName() const;
    int getQuantity() const;
    void setQuantity(int quantity);
    std::string toString() const;

private:
    std::string name;
    std::string category;
    int quantity;
    bool taken;
};


#endif //LISTONE_ITEM_H
