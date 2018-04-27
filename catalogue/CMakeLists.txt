cmake_minimum_required(VERSION 3.9)
project(catalogue)

include_directories(include)
include_directories(src)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
add_executable(catalogue main.cpp include/Product.hpp src/Product.cpp include/Catalogue.hpp src/Catalogue.cpp)