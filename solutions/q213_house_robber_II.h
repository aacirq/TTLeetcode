//
// Created by renxin on 2020/12/27.
//

#ifndef TTLEETCODE_Q213_HOUSE_ROBBER_II_H
#define TTLEETCODE_Q213_HOUSE_ROBBER_II_H

#include "../basic.h"

class Solution {
public:
    int rob(const vector<int> &nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        return max(rob_from_to(nums, 0, nums.size() - 1), rob_from_to(nums, 1, nums.size()));
    }

private:
    int rob_from_to(const vector<int> &nums, int bk, int ek) {
        if (ek <= bk) return 0;
        if (ek == bk + 1) return nums[bk];
        if (ek == bk + 2) return max(nums[bk], nums[bk + 1]);
        int first = nums[bk], second = max(nums[bk], nums[bk + 1]);
        for (int k = bk + 2; k < ek; ++k) {
            int tmp = second;
            second = max(first + nums[k], second);
            first = tmp;
        }
        return second;
    }
};

static void solve() {
    Solution s;
    cout << "0 : " << s.rob({  }) << endl;
    cout << "0 : " << s.rob({ 0 }) << endl;
    cout << "1 : " << s.rob({ 1 }) << endl;
    cout << "2 : " << s.rob({ 1, 2 }) << endl;
    cout << "2 : " << s.rob({ 2, 1 }) << endl;
    cout << "3 : " << s.rob({ 1, 2, 3 }) << endl;
    cout << "5 : " << s.rob({ 1, 5, 3 }) << endl;
    cout << "4 : " << s.rob({ 1, 2, 3, 1 }) << endl;
    cout << "11 : " << s.rob({ 2, 7, 9, 3, 1 }) << endl;
    cout << "3 : " << s.rob({ 2, 1, 1, 2 }) << endl;
    cout << "3 : " << s.rob({ 2, 3, 2 }) << endl;
    cout << "4 : " << s.rob({ 1, 2, 3, 1 }) << endl;
    cout << "3 : " << s.rob({ 1, 1, 1, 2 }) << endl;
    cout << "10 : " << s.rob({ 2, 2, 4, 3, 2, 5 }) << endl;
}

#endif // TTLEETCODE_Q213_HOUSE_ROBBER_II_H
