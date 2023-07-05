//
// Created by samuele on 01/07/23.
//

#include "ItemNotFound.h"

ItemNotFound::ItemNotFound(const std::string &arg) : runtime_error("'"+arg+"' not found.") {}
