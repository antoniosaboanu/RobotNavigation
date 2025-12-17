cmake_minimum_required(VERSION 3.10)

project(RobotNavigation)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fsanitize=address")


add_executable(RobotNavigation src/main.cpp 
    src/Node.cpp 
    src/Edge.cpp 
    src/Maze.cpp 
    src/RandomRobot.cpp
    src/WavefrontRobot.cpp)

target_include_directories(RobotNavigation PRIVATE include)