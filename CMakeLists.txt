cmake_minimum_required(VERSION 3.15)
project(PwdTools)

set(CMAKE_CXX_STANDARD 11)

add_executable(PwdTools pwd_tool.cpp tools/LenCount.cpp pwd_tool.h tools/LenCount.h)
add_executable(Test test.cpp)
add_executable(random_sample strategy/random_sample.cpp strategy/random_sample.h)
add_executable(k_folder strategy/k_folder.cpp strategy/k_folder.h)