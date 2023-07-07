//
// Created by samuele on 04/07/23.
//

#ifndef LISTONE_GENERICFILEERROR_H
#define LISTONE_GENERICFILEERROR_H

#include <exception>
#include <stdexcept>

class GenericFileError : public std::runtime_error{
public:
    explicit GenericFileError(const std::string &arg);
};


#endif //LISTONE_GENERICFILEERROR_H
