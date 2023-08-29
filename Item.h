//
// Created by samuele on 30/06/23.
//

#ifndef LISTONE_ITEM_H
#define LISTONE_ITEM_H


#include <string>

class Item {
public:
    Item(const std::string& name, const std::string&  category,int quantity = 0);
    ~Item() = default;

    bool operator==(const Item &rhs) const;
    bool operator!=(const Item &rhs) const;

    bool isChecked() const;
    void checkItem();
    void checkItem(bool check);
    const std::string &getName() const;
    int getQuantity() const;
    void setQuantity(int quantity);
    const std::string &getCategory() const;
    std::string toString() const;

private:
    std::string name;
    std::string category;
    int quantity;
    bool checked;
};


#endif //LISTONE_ITEM_H
