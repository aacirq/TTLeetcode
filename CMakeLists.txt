cmake_minimum_required(VERSION 3.17)
project(TTLeetcode)

set(CMAKE_CXX_STANDARD 11)

add_executable(TTLeetcode
        main.cpp
        basic.h
        Solutions/testSolution.h
        main_include.h
        basic.cpp
        Solutions/q237_delete_node_in_a_linked_list.h
        Solutions/q328_odd_even_linked_list.h
        Solutions/q138_copy_list_with_random_pointer.h
        Solutions/q103_binary_tree_zigzag_level_order_traversal.h
        Solutions/q104_maximum_depth_of_binary_tree.h
        Solutions/q105_construct_binary_tree_from_.h
        Solutions/q108_convert_sorted_array_to_.h Solutions/q116_populating_next_right_pointers_.h Solutions/q124_binary_tree_maximum_path_sum.h Solutions/q230_kth_smallest_element_in_a_bst.h)