cmake_minimum_required(VERSION 3.21)
project(Project2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project P2.cpp gridFlea.cpp gridFlea.h inFest.cpp inFest.h)
