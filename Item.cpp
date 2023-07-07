//
// Created by samuele on 30/06/23.
//

#include <stdexcept>
#include "Item.h"

Item::Item(std::string &name,std::string& category, int quantity) : name (name), category(category) , quantity (quantity){
    if(quantity < 0){
        throw std::runtime_error("Item quantity cannot be < 0");
    }
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

bool Item::isTaken() const {
    return taken;
}

void Item::checkItem() {
    taken = true;
}

void Item::unCheckItem() {
    taken = false;
}

std::string Item::toString() const{
    return name + ";" + category + ";" + std::to_string(quantity) + ";" + std::to_string(taken) +"; \n";
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

