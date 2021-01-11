cmake_minimum_required(VERSION 3.0)

project(lmd)

add_compile_options(
    -g
)

aux_source_directory(. LIB_SRCS)
aux_source_directory(lexer LIB_SRCS)
aux_source_directory(elements LIB_SRCS)

add_library(lmd ${LIB_SRCS})