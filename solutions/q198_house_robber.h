//
// Created by renxin on 2020/12/25.
//

#ifndef TTLEETCODE_Q198_HOUSE_ROBBER_H
#define TTLEETCODE_Q198_HOUSE_ROBBER_H

#include "../basic.h"

class Solution {
public:
    int rob(const vector<int> &nums) {
        if (nums.empty()) return 0;
        vector<int> n(nums.size());
        n[0] = nums[0];
        if (nums.size() == 1) return n[0];
        n[1] = nums[1];
        if (nums.size() == 2) return max(n[1], n[0]);
        n[2] = nums[2] + n[0];
        if (nums.size() == 3) return max(n[2], n[1]);
        int k;
        for (k = 3; k < nums.size(); ++k)
            n[k] = nums[k] + max(n[k - 2], n[k - 3]);
        return max(n[k - 1], n[k - 2]);
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
