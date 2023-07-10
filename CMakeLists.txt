cmake_minimum_required(VERSION 3.5)
project(Listone)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(test)

set(SOURCE_FILES User.cpp User.h List.cpp List.h Item.cpp Item.h Factories/ItemFactory.cpp Factories/ItemFactory.h Exceptions/ItemNotFound.cpp
        Exceptions/ItemNotFound.h Subject.h Observer.h Factories/Factory.cpp Factories/Factory.h Listone.cpp Listone.h Factories/UserFactory.cpp Factories/UserFactory.h
        Exceptions/GenericFileError.cpp Exceptions/GenericFileError.h Factories/ListFactory.cpp Factories/ListFactory.h Exceptions/UserNotFound.cpp Exceptions/UserNotFound.h
        Exceptions/ListNotFound.cpp Exceptions/ListNotFound.h ListUpdate.cpp ListUpdate.h Exceptions/UserNotLoggedIn.cpp Exceptions/UserNotLoggedIn.h Exceptions/IncorrectPassword.cpp
        Exceptions/IncorrectPassword.h)

add_executable(Listone main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(Listone core)

