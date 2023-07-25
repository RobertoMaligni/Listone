#ifndef LISTONE_ITEM_H
#define LISTONE_ITEM_H


#include <stdexcept>

class ApplicationException : public std::runtime_error{
public:

    enum class ErrorType :short{
        RunTime = 1,
        LoadingFile,
        CorruptedAppState,
        MissingSaveFiles,
    };

    explicit ApplicationException(ErrorType errorType);
    ApplicationException(ErrorType errorType, const std::string &error);


    ErrorType errorType;
};


#endif
