cmake_minimum_required(VERSION 3.21)
project(USTHC C)

set(CMAKE_C_STANDARD 17)

add_executable(USTHC main.c header.h divisible.c arrays.c functions.c determinant.c)
