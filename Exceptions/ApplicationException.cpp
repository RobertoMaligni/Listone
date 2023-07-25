#include "ApplicationException.h"

ApplicationException::ApplicationException(ApplicationException::ErrorType errorType, const std::string &error) : std::runtime_error(error){
    this->errorType = errorType;
}

ApplicationException::ErrorType ApplicationException::getErrorType() const {
    return errorType;
}
