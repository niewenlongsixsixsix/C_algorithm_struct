cmake_minimum_required(VERSION 3.15)
project(Algorithm_Struct C)

set(CMAKE_C_STANDARD 99)

add_executable(Algorithm_Struct main.c main.c list/c/list_array.c list/h/list_array.h list/c/list_single_linked.c list/h/list_single_linked.h)