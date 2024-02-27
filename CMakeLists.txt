cmake_minimum_required(VERSION 3.27)
project(monty C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(monty
        monty.c
        monty.h
        "monty_dep_list2.c"
        "monty_dep_list1.c"
        "monty_dep_std_fun2.c"
        mounty_main_fun.c
        "monty_dep_std_fun3.c"
        mounty_main_fun2.c
        mounty_main_fun3.c
        monty_dep_list3.c
        monty_dep_std_fun1.c
)
