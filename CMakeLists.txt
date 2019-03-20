cmake_minimum_required(VERSION 3.13)
project(Path)

set(CMAKE_CXX_STANDARD 17)

add_executable(Path main.cpp lib/Path.cpp include/Path.h)