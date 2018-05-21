cmake_minimum_required(VERSION 3.9)
project(nordic_semiconductor_test C)

set(CMAKE_C_STANDARD 99)

add_executable(nordic_semiconductor_test main.c max_num_from_digits.c max_num_from_digits.h sorts_lib.c sorts_lib.h local_extremas.c local_extremas.h)