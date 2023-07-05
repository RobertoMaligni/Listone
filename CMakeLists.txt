cmake_minimum_required(VERSION 3.25)
project(Listone)

set(CMAKE_CXX_STANDARD 11)

add_executable(Listone main.cpp User.cpp User.h List.cpp List.h Item.cpp Item.h ItemFactory.cpp ItemFactory.h Exceptions/ItemNotFound.cpp Exceptions/ItemNotFound.h Subject.h Observer.h AbstractFactory.cpp AbstractFactory.h Listone.cpp Listone.h UserFactory.cpp UserFactory.h AbstractProduct.h AbstractProduct.cpp Exceptions/FileError.cpp Exceptions/FileError.h)
