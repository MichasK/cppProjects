cmake_minimum_required(VERSION 3.9)
include_directories(src)
file(GLOB SOURCES src/*.c)
project(C_trainee C)

set(CMAKE_C_STANDARD 99)

add_executable(C_trainee main.c src/basic_algo.c src/basic_algo.h src/matrix.c src/matrix.h)
target_link_libraries(C_trainee m)