cmake_minimum_required(VERSION 3.25)

project(Calculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

add_executable(calc
    src/main.cpp
)

target_link_libraries(calc gtest::gtest)
