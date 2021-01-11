cmake_minimum_required(VERSION 3.0)

project(lmd_test)

aux_source_directory(. TEST_SRCS)
aux_source_directory(lexer TEST_SRCS)

add_compile_options(
    -g
)

include_directories(
    ${CMAKE_SOURCE_DIR}
)

link_libraries(
    pthread
    gtest
    lmd
)

add_executable(test_main ${TEST_SRCS})

