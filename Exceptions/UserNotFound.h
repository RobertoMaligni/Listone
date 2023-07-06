//
// Created by samuele on 06/07/23.
//

#ifndef LISTONE_USERNOTFOUND_H
#define LISTONE_USERNOTFOUND_H


#include <stdexcept>

class UserNotFound : public std::runtime_error{
public:
    explicit UserNotFound(const std::string &arg);
};


#endif //LISTONE_USERNOTFOUND_H
