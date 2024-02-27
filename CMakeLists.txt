cmake_minimum_required(VERSION 3.27)
project(monty C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(monty
        monty.c
        monty.h
        "monty_dep2_list.c"
        "monty_dep1_list.c"
        "monty_dep4_std_fun.c"
        mounty_main_fun.c
        "monty_dep3_std_fun.c"
        mounty_main_fun2.c
        mounty_main_fun3.c
)
