#include "ApplicationException.h"

ApplicationException::ApplicationException(ApplicationException::ErrorType errorType, const std::string &error) : std::runtime_error(error){
    this->errorType = errorType;
}

ApplicationException::ApplicationException(ApplicationException::ErrorType errorType) : std::runtime_error("") {
    this->errorType = errorType;
}
