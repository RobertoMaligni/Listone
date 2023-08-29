//
// Created by samuele on 30/06/23.
//

#include <stdexcept>
#include "Item.h"

Item::Item(const std::string& name,const std::string& category, int quantity) : name (name), category(category) , quantity (quantity){
    if(quantity < 0){
        throw std::runtime_error("Item quantity cannot be < 0");
    }
    checked = false;
}

const std::string &Item::getName() const {
    return name;
}

int Item::getQuantity() const {
    return quantity;
}

void Item::setQuantity(int quantity) {
    Item::quantity = quantity;
}

bool Item::isChecked() const {
    return checked;
}

void Item::checkItem() {
    checked = !checked;
}

void Item::checkItem(bool check) {
    checked = check;
}

std::string Item::toString() const{
    return name + ";" + category + ";" + std::to_string(quantity) + ";" + std::to_string(checked) + "; \n";
}

bool Item::operator==(const Item &rhs) const {
    return name == rhs.name &&
           category == rhs.category;
}

bool Item::operator!=(const Item &rhs) const {
    return !(rhs == *this);
}

const std::string &Item::getCategory() const {
    return category;
}

