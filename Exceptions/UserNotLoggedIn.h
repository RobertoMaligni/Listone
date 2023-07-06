//
// Created by samuele on 06/07/23.
//

#ifndef LISTONE_USERNOTLOGGEDIN_H
#define LISTONE_USERNOTLOGGEDIN_H


#include <stdexcept>

class UserNotLoggedIn : public std::runtime_error{
public:
    explicit UserNotLoggedIn();
};


#endif //LISTONE_USERNOTLOGGEDIN_H
