#ifndef LISTONE_APPLICATIONEXCEPTION_H
#define LISTONE_APPLICATIONEXCEPTION_H


#include <stdexcept>

class ApplicationException : public std::runtime_error{
public:

    enum class ErrorType :short{
        RunTime = 1,
        LoadingFile,
        CorruptedAppState,
        MissingSaveFiles,
    };

    explicit ApplicationException(ErrorType errorType, const std::string &error = "");
    ErrorType getErrorType() const;

private:
    ErrorType errorType;
};


#endif
