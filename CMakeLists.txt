cmake_minimum_required (VERSION 3.14)

project (vector_tools VERSION 0.0.1)

# Configure version
configure_file("src/cpp/config.h.in" "${PROJECT_BINARY_DIR}/config.h")

# Find eigen
set(CMAKE_PREFIX_PATH $ENV{HOME} $ENV{HOME}/local/ $ENV{HOME}/.local ${CMAKE_PREFIX_PATH})
set(ENV{EIGEN_ROOT} "$ENV{HOME}/include")
set(ENV{EIGEN_ROOT_DIR} "$ENV{HOME}/include")
find_package (Eigen3 3.3 REQUIRED NO_MODULE)
include_directories(${EIGEN3_INCLUDE_DIR})

# Add the cmake folder to locate the FindSphinx module
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

# Add source directory to help tests find library
include_directories("src/cpp")

# Add source code directories
add_subdirectory ("src/cpp")
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    add_subdirectory ("src/cpp/tests/${PROJECT_NAME}")
    add_subdirectory ("docs")
endif()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-std=gnu++11 -Wall -ansi -pedantic -O3 -I. -fmax-errors=5")
