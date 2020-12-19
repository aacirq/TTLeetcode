//
// Created by renxin on 2020/12/19.
// 本文件包括5种二分查找，区别在于与目标值target的关系
// binary_search_standard:         标准二分查找，找到元素返回下标，没找到返回-1
// binary_search_min_larger_equal: 查找所有大于等于target值中最小的，如果没有元素大于等于target，返回-1
// binary_search_min_larger:       查找所有大于target值中最小的，如果没有元素大于target，返回-1
// binary_search_max_less_equal:   查找所有小于等于target值中最大的，如果没有元素小于等于target，返回-1
// binary_search_max_less:         查找所有小于target值中最大的，如果没有元素小于target，返回-1
//

#ifndef TTLEETCODE_BINARY_SEARCH_H
#define TTLEETCODE_BINARY_SEARCH_H

#include "../basic.h"

class Search {
public:
    static int binary_search_standard(const vector<int> &arr, int target) {
        int left = 0, right = arr.size() - 1;
        int mid;
        while(left < right) {
            mid = left + (right - left) / 2;
            if(arr[mid] < target)
                left = mid + 1;
            else if(arr[mid] > target)
                right = mid;
            else
                left = right = mid;
        }
        if(arr[left] == target)
            return left;
        else
            return -1;
    }

    static int binary_search_min_larger_equal(const vector<int> &arr, int target) {
        int left = 0, right = arr.size() - 1;
        int mid;
        while(left < right) {
            mid = left + (right - left) / 2;
            if(arr[mid] < target)
                left = mid + 1;
            else if(arr[mid] > target)
                right = mid;
            else
                left = right = mid;
        }
        if(arr[left] >= target)
            return left;
        else
            return -1;
    }

    static int binary_search_min_larger(const vector<int> &arr, int target) {
        int left = 0, right = arr.size() - 1;
        int mid;
        while(left < right) {
            mid = left + (right - left) / 2;
            if(arr[mid] < target)
                left = mid + 1;
            else if(arr[mid] > target)
                right = mid;
            else
                left = right = mid;
        }
        if(arr[left] > target)
            return left;
        else if(arr[left] == target && left + 1 < arr.size())
            return left + 1;
        else
            return -1;
    }

    static int binary_search_max_less_equal(const vector<int> &arr, int target) {
        int left = 0, right = arr.size() - 1;
        int mid;
        while(left < right) {
            mid = left + (right - left) / 2;
            if(arr[mid] < target)
                left = mid + 1;
            else if(arr[mid] > target)
                right = mid;
            else
                left = right = mid;
        }
        if(arr[left] == target)
            return left;
        else if(arr[left] > target)
            if(left > 0) return left - 1;
            else         return -1;
        else
            return left;
    }

    static int binary_search_max_less(const vector<int> &arr, int target) {
        int left = 0, right = arr.size() - 1;
        int mid;
        while(left < right) {
            mid = left + (right - left) / 2;
            if(arr[mid] < target)
                left = mid + 1;
            else if(arr[mid] > target)
                right = mid;
            else
                left = right = mid;
        }
        if(arr[left] >= target)
            if(left > 0) return left - 1;
            else         return -1;
        else
            return left;
    }
};

static void test_binary_search(const vector<int> vec, const vector<int> target_vec, int (*search_fun)(const vector<int> &, int)) {
    vector<int> ret(target_vec.size());

    for (int i = 0; i < target_vec.size(); ++i)
        ret[i] = search_fun(vec, target_vec[i]);
    cout << "vec: ";
    for (auto i : vec)
        printf("%4d", i);
    cout << endl << "tar: ";
    for (auto i : target_vec)
        printf("%4d", i);
    cout << endl << "ret: ";
    for (auto i : ret)
        printf("%4d", i);
    cout << endl;
}

static void solve() {
    vector<int> vec = { 1, 3, 5, 7, 9 };
    vector<int> target_vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    cout << "binary search (standard)" << endl;
    test_binary_search(vec, target_vec, Search::binary_search_standard);

    cout << endl;
    cout << "binary search (minimum of all elements <larger equal> than target)" << endl;
    test_binary_search(vec, target_vec, Search::binary_search_min_larger_equal);

    cout << endl;
    cout << "binary search (minimum of all elements <larger> than target)" << endl;
    test_binary_search(vec, target_vec, Search::binary_search_min_larger);

    cout << endl;
    cout << "binary search (maximum of all elements <less equal> than target)" << endl;
    test_binary_search(vec, target_vec, Search::binary_search_max_less_equal);

    cout << endl;
    cout << "binary search (maximum of all elements <less> than target)" << endl;
    test_binary_search(vec, target_vec, Search::binary_search_max_less);
}

#endif // TTLEETCODE_BINARY_SEARCH_H
