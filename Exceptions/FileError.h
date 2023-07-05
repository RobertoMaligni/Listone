//
// Created by samuele on 04/07/23.
//

#ifndef LISTONE_FILEERROR_H
#define LISTONE_FILEERROR_H

#include <exception>
#include <stdexcept>

class FileError : public std::runtime_error{
public:
    explicit FileError(const std::string &arg);
};


#endif //LISTONE_FILEERROR_H
