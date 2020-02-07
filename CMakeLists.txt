cmake_minimum_required (VERSION 2.8)

project ("vector_tools")

add_subdirectory ("src/cpp")
#add_subdirectory ("docs")

add_library(vector_tools vector_tools.cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
