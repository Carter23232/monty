cmake_minimum_required(VERSION 3.27)
project(monty C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(monty
        monty.c
        monty.h
        "monty_dep2(linked_list_func).c"
        "monty_dep1(linked_list_func).c"
        "monty_dep4(std_fun).c"
        mounty_main_fun.c
        "monty_dep3(std_fun).c"
)
