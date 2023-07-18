cmake_minimum_required(VERSION 3.5)
project(Listone)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(test)

set(SOURCE_FILES User.cpp User.h List.cpp List.h Item.cpp Item.h FileHandlers/InventoryHandler.cpp FileHandlers/InventoryHandler.h Exceptions/ItemNotFound.cpp
        Exceptions/ItemNotFound.h Subject.h Observer.h FileHandlers/FileHandler.cpp FileHandlers/FileHandler.h Listone.cpp Listone.h FileHandlers/UserHandler.cpp FileHandlers/UserHandler.h
        Exceptions/GenericFileError.cpp Exceptions/GenericFileError.h FileHandlers/ListHandler.cpp FileHandlers/ListHandler.h
        Exceptions/UserNotLoggedIn.cpp Exceptions/UserNotLoggedIn.h Exceptions/IncorrectPassword.cpp
        Exceptions/IncorrectPassword.h)

add_executable(Listone main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(Listone core)

