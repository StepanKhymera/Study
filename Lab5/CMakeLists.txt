cmake_minimum_required(VERSION 3.9)
project(Lab5 C)

set(CMAKE_C_STANDARD 99)

add_executable(Lab5 main.c function.h function.c)
target_link_libraries(Lab5 m)