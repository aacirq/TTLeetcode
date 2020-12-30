//
// Created by renxin on 2020/12/30.
//

#ifndef TTLEETCODE_Q96_UNIQUE_BINARY_SEARCH_TREES_H
#define TTLEETCODE_Q96_UNIQUE_BINARY_SEARCH_TREES_H

#include "../basic.h"

#if 0

// 利用迭代计算的方法
class Solution {
public:
    int numTrees(int n) {
        vector<int> vec(n + 1);
        vec[0] = 1;
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < i; ++j) {
                vec[i] += vec[j] * vec[i - j - 1];
            }
        }
        return vec[n];
    }
};

#else

// 利用卡塔兰数通解 https://baike.baidu.com/item/catalan/7605685?fr=aladdin
// 注意 c = c * 2 * (2 * i + 1) / (i + 2); 这一行，右侧计算要把c放在前面，避免整除的时候丢弃小数导致错误
// 注意数据是long long，避免溢出
class Solution {
public:
    int numTrees(int n) {
        long long c = 1;
        for (int i = 0; i < n; ++i)
            c = c * 2 * (2 * i + 1) / (i + 2);
        return (int)c;
    }
};

#endif

static void solve() {
    Solution s;
    cout << s.numTrees(3) << endl;
}

#endif // TTLEETCODE_Q96_UNIQUE_BINARY_SEARCH_TREES_H
