cmake_minimum_required(VERSION 3.17)
project(TTLeetcode)

set(CMAKE_CXX_STANDARD 11)

add_executable(TTLeetcode main.cpp basic.h Solutions/testSolution.h main_include.h basic.cpp Solutions/q237_delete_node_in_a_linked_list.h Solutions/q328_odd_even_linked_list.h Solutions/q138_copy_list_with_random_pointer.h)