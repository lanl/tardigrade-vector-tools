#===================================================================================================== PROJECT SETUP ===
cmake_minimum_required(VERSION 3.14)
project(vector_tools VERSION 0.2.0)
enable_testing()

# Set common project paths relative to project root directory
set(CPP_SRC_PATH "src/cpp")
set(CMAKE_SRC_PATH "src/cmake")

# Add installation directory variables
include(GNUInstallDirs)

# Set the c++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-Wall -ansi -pedantic -O3 -fmax-errors=5")

#================================================================================================= FIND DEPENDENCIES ===
# Find eigen
find_package(Eigen3 3.3 REQUIRED NO_MODULE)
include_directories(${EIGEN3_INCLUDE_DIR})
if(EIGEN3_FOUND)
    message(STATUS "Found Eigen3: ${EIGEN3_INCLUDE_DIR}")
endif()

# Add the cmake folder to locate the FindSphinx module
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/${CMAKE_SRC_PATH}" ${CMAKE_MODULE_PATH})

#=============================================================================================== ADD PROJECT TARGETS ===
# MUST COME AFTER DEPENDENCY LOCATING
# Add include directory for use by all libraries and executables in this project
include_directories("${CPP_SRC_PATH}")

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

#==================================================================================== SETUP INSTALLATION CMAKE FILES ===
include(CMakePackageConfigHelpers)
write_basic_package_version_file("${PROJECT_NAME}ConfigVersion.cmake"
                                 VERSION ${PROJECT_VERSION}
                                 COMPATIBILITY SameMajorVersion)
configure_package_config_file(
  "${PROJECT_SOURCE_DIR}/${CMAKE_SRC_PATH}/${PROJECT_NAME}Config.cmake.in"
  "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
  INSTALL_DESTINATION
  ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)

# CMake won't build the targets for local builds of upstream projects
if(cmake_build_type_lower STREQUAL release)
    install(EXPORT ${PROJECT_NAME}_Targets
            FILE ${PROJECT_NAME}Targets.cmake
            DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)
endif()

install(FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
              "${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)
