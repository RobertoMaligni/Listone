//
// Created by samuele on 06/07/23.
//

#include "ListNotFound.h"

ListNotFound::ListNotFound(const std::string &arg) : runtime_error("'"+arg+"' not found.") {}