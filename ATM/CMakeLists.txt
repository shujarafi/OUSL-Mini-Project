cmake_minimum_required(VERSION 3.12)
project(gini C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(gini
        customer.h
        filehandle.h
        main.c)
