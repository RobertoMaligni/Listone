//
// Created by samuele on 01/07/23.
//

#ifndef LISTONE_ITEMNOTFOUND_H
#define LISTONE_ITEMNOTFOUND_H


#include <exception>
#include <stdexcept>

class ItemNotFound : public std::runtime_error {
public:
    explicit ItemNotFound(const std::string &arg);

};


#endif //LISTONE_ITEMNOTFOUND_H
