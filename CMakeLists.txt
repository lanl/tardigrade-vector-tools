cmake_minimum_required (VERSION 3.14)

project (vector_tools)

# Find eigen
#find_package (Eigen3 3.3 REQUIRED NO_MODULE)
get_filename_component(EIGEN_ABS_PATH "../eigen" ABSOLUTE)

# Add the cmake folder to locate the FindSphinx module
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

add_subdirectory ("src/cpp")
add_subdirectory ("docs")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-std=gnu++11 -Wall -ansi -pedantic -O3 -I. -fmax-errors=5 -I${EIGEN_ABS_PATH}")
