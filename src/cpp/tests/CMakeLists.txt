set(TEST_NAME "test_${PROJECT_NAME}")

add_executable (${TEST_NAME} "${TEST_NAME}.cpp")
add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})

set_target_properties(${TEST_NAME} PROPERTIES CXX_STANDARD 11)
target_compile_options(${TEST_NAME} PRIVATE)

target_include_directories(${TEST_NAME} PRIVATE ${Boost_INCLUDE_DIRS})
