cmake_minimum_required(VERSION 3.22)
project(csnake C)

set(CMAKE_C_STANDARD 11)

add_executable(csnake main.c
        snake.h)

#link ncurses
target_link_libraries(csnake ncurses)
