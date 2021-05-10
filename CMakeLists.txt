#===================================================================================================== PROJECT SETUP ===
cmake_minimum_required (VERSION 3.14)
project(vector_tools VERSION 0.1.0)
enable_testing()

# Set common project paths relative to project root directory
set(CPP_SRC_PATH "src/cpp")
set(CMAKE_SRC_PATH "src/cmake")

# Add installation directory variables
include(GNUInstallDirs)

# Find eigen
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} $ENV{HOME}/.local $ENV{HOME}/local/ $ENV{HOME})
find_package(Eigen3 3.3 REQUIRED NO_MODULE)
include_directories(${EIGEN3_INCLUDE_DIR})

# Add the cmake folder to locate the FindSphinx module
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/${CMAKE_SRC_PATH}" ${CMAKE_MODULE_PATH})

# Set the c++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-Wall -ansi -pedantic -O3 -I. -fmax-errors=5")

#=============================================================================================== ADD PROJECT TARGETS ===
# MUST COME AFTER DEPENDENCY LOCATING
# Configure version in project header and add to include directory for use by all libraries and executables in this project
configure_file("${CPP_SRC_PATH}/${PROJECT_NAME}.h.in" "${PROJECT_BINARY_DIR}/${CPP_SRC_PATH}/${PROJECT_NAME}.h")
include_directories("${PROJECT_BINARY_DIR}/${CPP_SRC_PATH}")

# Add project source directories
add_subdirectory("${CPP_SRC_PATH}")

# Only add tests and documentation for current project builds. Protects downstream project builds.
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    # Find Boost. Required for tests
    find_package(Boost 1.53.0 REQUIRED COMPONENTS unit_test_framework)
    # Add c++ tests and docs
    add_subdirectory("${CPP_SRC_PATH}/tests")
    add_subdirectory("docs")
endif()
