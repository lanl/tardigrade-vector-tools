add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE
                           INTERFACE $<BUILD_INTERFACE:${CPP_SRC_PATH}>
                                     $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
target_compile_features(${PROJECT_NAME} INTERFACE CXX_STD_11)
install(TARGETS ${PROJECT_NAME}
        PUBLIC_HEADER)
