//
// Created by samuele on 07/07/23.
//

#include "IncorrectPassword.h"

IncorrectPassword::IncorrectUsernameOrPassword() : std::runtime_error("Password not correct.") {

}