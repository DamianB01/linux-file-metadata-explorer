cmake_minimum_required(VERSION 4.2)
project(zadanie5 C)

set(CMAKE_C_STANDARD 11)

add_executable(zadanie5 main.c
        catalog_rec.h
        catalog_rec.c
        file_print.c
        file_print.h
        file_type.c
        file_type.h)
