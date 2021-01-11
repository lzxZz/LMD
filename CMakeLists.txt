cmake_minimum_required(VERSION 3.0)

add_compile_options(-Wall)

include_directories(
    ${CMAKE_SOURCE_DIR}
)

add_subdirectory(test)

add_subdirectory(lmd)