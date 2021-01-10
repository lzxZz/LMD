cmake_minimum_required(VERSION 3.0)

project(lmd)



aux_source_directory(. LIB_SRCS)
aux_source_directory(lexer LIB_SRCS)

add_library(lmd ${LIB_SRCS})