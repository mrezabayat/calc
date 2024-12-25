cmake_minimum_required(VERSION 3.25)

project(Calculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
find_package(GTest REQUIRED)

add_executable(calc
    src/Calculator.cpp
    src/Calculator.h
    src/Constants.h
    src/main.cpp
    src/TokenStream.cpp
    src/TokenStream.h
    src/Variables.cpp
    src/Variables.h
)

target_link_libraries(calc gtest::gtest)
