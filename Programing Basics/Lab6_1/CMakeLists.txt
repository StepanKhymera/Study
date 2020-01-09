cmake_minimum_required(VERSION 3.9)
project(Lab6_1 C)

set(CMAKE_C_STANDARD 99)

add_executable(Lab6_1 main.c Lab6_1.h Lab6_1.c)
link_libraries(Lab6_1 d)