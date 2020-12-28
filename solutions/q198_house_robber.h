//
// Created by renxin on 2020/12/25.
// 到第k个点的最大值n[k] = max(nums[k] + n[k - 2], n[k - 1]);
//

#ifndef TTLEETCODE_Q198_HOUSE_ROBBER_H
#define TTLEETCODE_Q198_HOUSE_ROBBER_H

#include "../basic.h"

class Solution {
public:
    int rob(const vector<int> &nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        int first = nums[0], second = max(nums[0], nums[1]);
        for (int k = 2; k < nums.size(); ++k) {
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
    cout << "1 : " << s.rob({ 1 }) << endl;
    cout << "2 : " << s.rob({ 1, 2 }) << endl;
    cout << "4 : " << s.rob({ 1, 2, 3 }) << endl;
    cout << "5 : " << s.rob({ 1, 5, 3 }) << endl;
    cout << "4 : " << s.rob({ 1, 2, 3, 1 }) << endl;
    cout << "12 : " << s.rob({ 2, 7, 9, 3, 1 }) << endl;
    cout << "4 : " << s.rob({ 2, 1, 1, 2 }) << endl;
}

#endif // TTLEETCODE_Q198_HOUSE_ROBBER_H
