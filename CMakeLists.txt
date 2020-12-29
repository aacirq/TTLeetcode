cmake_minimum_required(VERSION 3.17)
project(TTLeetcode)

set(CMAKE_CXX_STANDARD 11)

add_executable(TTLeetcode
        main.cpp
        basic.h
        solutions/testSolution.h
        main_include.h
        basic.cpp

        typical_implement/binary_tree_traverse.h
        typical_implement/binary_search.h

        solutions/q237_delete_node_in_a_linked_list.h
        solutions/q328_odd_even_linked_list.h
        solutions/q138_copy_list_with_random_pointer.h
        solutions/q103_binary_tree_zigzag_level_order_traversal.h
        solutions/q104_maximum_depth_of_binary_tree.h
        solutions/q105_construct_binary_tree_from_.h
        solutions/q108_convert_sorted_array_to_.h
        solutions/q116_populating_next_right_pointers_.h
        solutions/q124_binary_tree_maximum_path_sum.h
        solutions/q230_kth_smallest_element_in_a_bst.h
        solutions/q144_binary_tree_preorder_traversal.h
        solutions/q145_binary_tree_postorder_traversal.h
        solutions/q114_flatten_binary_tree_to_linked_list.h
        solutions/q226_invert_binary_tree.h
        solutions/q236_lowest_common_ancestor_of_a_binary_tree.h
        solutions/q297_serialize_and_deserialize_binary_tree.h
        solutions/q198_house_robber.h
        solutions/q213_house_robber_II.h
        solutions/q337_house_robber_III.h
        solutions/q112_path_sum.h
        solutions/q113_path_sum_ii.h
        solutions/q437_path_sum_iii.h
        solutions/q538_convert_bst_to_greater_tree.h
        solutions/q617_merge_two_binary_trees.h)