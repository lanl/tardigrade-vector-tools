add_library (vector_tools "vector_tools.cpp" "vector_tools.h")

target_include_directories(vector_tools PUBLIC .)
set_target_properties(vector_tools PROPERTIES CXX_STANDARD 11)

#target_link_libraries (vector_tools Eigen3::Eigen)
