cmake_minimum_required(VERSION 3.25)
project(Listone)

set(CMAKE_CXX_STANDARD 11)

add_executable(Listone main.cpp User.cpp User.h List.cpp List.h Item.cpp Item.h ItemFactory.cpp ItemFactory.h Exceptions/ItemNotFound.cpp Exceptions/ItemNotFound.h Subject.h Observer.h Factory.cpp Factory.h Listone.cpp Listone.h UserFactory.cpp UserFactory.h Exceptions/FileError.cpp Exceptions/FileError.h ListFactory.cpp ListFactory.h Exceptions/UserNotFound.cpp Exceptions/UserNotFound.h Exceptions/ListNotFound.cpp Exceptions/ListNotFound.h)
