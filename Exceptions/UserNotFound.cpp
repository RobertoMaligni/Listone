//
// Created by samuele on 06/07/23.
//

#include "UserNotFound.h"

UserNotFound::UserNotFound(const std::string &arg) : runtime_error("'"+arg+"' not found.") {}