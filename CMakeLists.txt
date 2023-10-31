cmake_minimum_required(VERSION 3.26)
project(ex_01 C)

set(CMAKE_C_STANDARD 99)

include_directories(.)

add_executable(ex_01
        ZDS.c
)
