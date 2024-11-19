cmake_minimum_required(VERSION 3.16)

project(the_missing_asterisk)

add_compile_options(-Wall -Wextra -pedantic)

add_executable(the_missing_asterisk_infinite main_infinite.c)
add_executable(the_missing_asterisk main.c)