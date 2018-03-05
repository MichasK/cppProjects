cmake_minimum_required(VERSION 3.9)
project(FactorySimulation)

set(CMAKE_CXX_STANDARD 14)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Wconversion")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)
include_directories(include)
include_directories(src)

file(GLOB SOURCES src/*.cpp)
file(GLOB TEST_SOURCES test/*.cpp)

add_executable(FactorySimulation main.cpp ${SOURCES} ${TEST_SOURCES})
target_link_libraries(FactorySimulation gtest)
