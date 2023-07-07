//
// Created by samuele on 07/07/23.
//

#ifndef LISTONE_INCORRECTPASSWORD_H
#define LISTONE_INCORRECTPASSWORD_H


#include <stdexcept>

class IncorrectPassword : public std::runtime_error{
public:
    explicit IncorrectPassword();
};


#endif //LISTONE_INCORRECTPASSWORD_H
