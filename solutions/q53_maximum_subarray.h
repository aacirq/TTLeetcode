//
// Created by renxin on 2021/1/3.
// TODO: divide and conquer method
//

#ifndef TTLEETCODE_Q53_MAXIMUM_SUBARRAY_H
#define TTLEETCODE_Q53_MAXIMUM_SUBARRAY_H

#include "../basic.h"

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int max_num = INT32_MIN;
        int tmp_sum = 0;
        for (auto i : nums) {
            tmp_sum += i;
            if (tmp_sum > max_num) max_num = tmp_sum;
            if (tmp_sum < 0) tmp_sum = 0;
        }
        return max_num;
    }
};

static Solution s;

static void test_solution(vector<int> vec, int respect) {
    display(vec);
    cout << respect << " : " << s.maxSubArray(vec) << endl;
}

static void solve() {
    test_solution({ -2, 1, -3, 4, -1, 2, 1, -5, 4 }, 6);
    test_solution({ 1 }, 1);
    test_solution({ 0 }, 0);
    test_solution({ -1 }, -1);
    test_solution({ -2147483647 }, -2147483647);
}

#endif // TTLEETCODE_Q53_MAXIMUM_SUBARRAY_H
