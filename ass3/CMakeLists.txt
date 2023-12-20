cmake_minimum_required(VERSION 3.9)
project(ass3)

set(CMAKE_CXX_STANDARD 14)
    clang-tidy;
            -header-filter=.*;
            -checks=*,-llvmlibc-restrict-system-libc-headers;
            -warnings-as-errors=*;)

# need to load data files from current directory as cpp files
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(ass3 main.cpp maze.cpp maze.h creature.cpp creature.h)