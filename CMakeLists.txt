cmake_minimum_required(VERSION 3.15)
project(PwdTools)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(LenCount tools_cpp/LenCount.cpp tools_cpp/LenCount.h)
target_link_libraries(LenCount ${CMAKE_CURRENT_SOURCE_DIR}/include/clipp.h ${CMAKE_CURRENT_SOURCE_DIR}/include/json.hpp)

add_executable(Test test.cpp)
target_link_libraries(Test ${CMAKE_CURRENT_SOURCE_DIR}/include/clipp.h ${CMAKE_CURRENT_SOURCE_DIR}/include/json.hpp)

add_executable(RandSamp strategy/random_sample.cpp strategy/random_sample.h)
target_link_libraries(RandSamp ${CMAKE_CURRENT_SOURCE_DIR}/include/clipp.h ${CMAKE_CURRENT_SOURCE_DIR}/include/json.hpp)

add_executable(K_fold strategy/k_folder.cpp strategy/k_folder.h)
target_link_libraries(K_fold ${CMAKE_CURRENT_SOURCE_DIR}/include/clipp.h ${CMAKE_CURRENT_SOURCE_DIR}/include/json.hpp)
