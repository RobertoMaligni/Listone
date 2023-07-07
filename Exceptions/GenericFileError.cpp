//
// Created by samuele on 04/07/23.
//

#include "GenericFileError.h"

GenericFileError::GenericFileError(const std::string &arg) : runtime_error("Error while handling file '" + arg + "'") {}
