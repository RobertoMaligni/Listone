cmake_minimum_required(VERSION 3.5)
project(Listone)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

add_subdirectory(test)

set(SOURCE_FILES User.cpp User.h List.cpp List.h Item.cpp Item.h FileHandlers/InventoryHandler.cpp FileHandlers/InventoryHandler.h
        Subject.h Observer.h FileHandlers/FileHandler.cpp FileHandlers/FileHandler.h Listone.cpp Listone.h FileHandlers/UserHandler.cpp FileHandlers/UserHandler.h
        FileHandlers/ListHandler.cpp FileHandlers/ListHandler.h
        State.h State.cpp Exceptions/ApplicationException.cpp Exceptions/ApplicationException.h StartMenu.cpp StartMenu.h
        UserMenu.cpp
        UserMenu.h)

add_executable(Listone main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(Listone core)

