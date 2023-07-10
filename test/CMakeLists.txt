cmake_minimum_required(VERSION 3.5)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(SOURCE_FILES runAllTests.cpp runFactoryTests.cpp runListoneTests.cpp)
add_executable(runListoneTests.cpp ${SOURCE_FILES})
target_link_libraries(runListoneTests.cpp ${GTEST_BOTH_LIBRARIES} core)