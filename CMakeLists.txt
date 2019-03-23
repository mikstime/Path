cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 17)

project(Path)

set(SOURCE_LIB include/Path.h lib/Path.cpp)

add_library(Path STATIC ${SOURCE_LIB})