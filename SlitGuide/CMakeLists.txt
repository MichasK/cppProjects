cmake_minimum_required(VERSION 3.9)
project(SlitGuide)

set(CMAKE_CXX_STANDARD 14)

find_package( OpenCV REQUIRED )
set(SOURCE_FILES main.cpp src/Frame.cpp src/Frame.hpp src/AstronomicFrame.cpp src/FrameData.hpp src/Types.hpp)
add_executable(SlitGuide ${SOURCE_FILES} src/AstronomicFrame.hpp)
include_directories(${OpenCV_INCLUDE_DIRS})


target_link_libraries( SlitGuide ${OpenCV_LIBS} )