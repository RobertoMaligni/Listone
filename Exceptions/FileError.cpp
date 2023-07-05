//
// Created by samuele on 04/07/23.
//

#include "FileError.h"

FileError::FileError(const std::string &arg) : runtime_error("Error while handling file '"+arg+"'") {}
