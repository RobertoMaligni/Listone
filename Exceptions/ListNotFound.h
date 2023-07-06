//
// Created by samuele on 06/07/23.
//

#ifndef LISTONE_LISTNOTFOUND_H
#define LISTONE_LISTNOTFOUND_H

#include <stdexcept>

class ListNotFound : public std::runtime_error{
public:
    explicit ListNotFound(const std::string &arg);
};


#endif //LISTONE_LISTNOTFOUND_H
