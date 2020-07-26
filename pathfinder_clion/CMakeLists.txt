cmake_minimum_required(VERSION 3.16)
project(pathfinder_clion C)

set(CMAKE_C_STANDARD 11)

include_directories(inc)
include_directories(libmx/inc)
link_directories(libmx)

add_executable(pathfinder_clion src/mx_error_check.c src/main.c src/mx_error_1.c src/mx_error_2.c src/mx_error_3.c src/mx_error_4.c src/mx_error_5.c src/mx_count_character.c src/mx_read_one_line.c src/mx_error_6.c src/mx_del_not_alphabet.c src/mx_atoi.c)
target_link_libraries(pathfinder_clion libmx.a)