cmake_minimum_required(VERSION 3.25)

project(Calculator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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
