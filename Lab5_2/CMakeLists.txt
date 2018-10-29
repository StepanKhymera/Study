cmake_minimum_required(VERSION 3.9)
project(Lab5_2 C)

set(CMAKE_C_STANDARD 99)

add_executable(Lab5_2 main.c functions2.h function2.c)
target_link_libraries(Lab5_2 m)