cmake_minimum_required(VERSION 3.15)
project(PwdTools)

set(CMAKE_CXX_STANDARD 11)

add_executable(PwdTools main.cpp tools/LenCount.cpp main.h tools/LenCount.h)
add_executable(Test test.cpp)