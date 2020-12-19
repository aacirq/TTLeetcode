//
// Created by renxin on 2020/12/17.
// 思路是对的，也是好的，但是在自己实现的时候，用了太多的判断，导致运行时间长
// 保存了旧代码，也保存了新的代码
//

#ifndef TTLEETCODE_Q124_BINARY_TREE_MAXIMUM_PATH_SUM_H
#define TTLEETCODE_Q124_BINARY_TREE_MAXIMUM_PATH_SUM_H

#include "../basic.h"

#if 0
// po代码，fun函数里面太多判断了，可以精简
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        cur_max = INT32_MIN;
        fun(root);
        return cur_max;
    }

private:
    int fun(TreeNode *root) {
        if (root == nullptr) return 0;
        int num_left = fun(root->left);
        int num_right = fun(root->right);
        if (num_left <= 0 && num_right <= 0) {
            cur_max = max(root->val, cur_max);
            return root->val;
        } else if (num_left <= 0) {
            cur_max = max(root->val + num_right, cur_max);
            return root->val + num_right;
        } else if (num_right <= 0) {
            cur_max = max(root->val + num_left, cur_max);
            return root->val + num_left;
        } else {
            cur_max = max(num_left + num_right + root->val, cur_max);
            return root->val + max(num_left, num_right);
        }
    }

    int cur_max;
};

#else

class Solution {
private:
    int cur_max = INT32_MIN;
public:
    int maxPathSum(TreeNode *root) {
        fun(root);
        return cur_max;
    }

private:
    int fun(TreeNode *root) {
        if (root == nullptr) return 0;
        int num_left = max(fun(root->left), 0);
        int num_right = max(fun(root->right), 0);
        cur_max = max(cur_max, num_left + num_right + root->val);
        return root->val + max(num_left, num_right);
    }
};

#endif

static void solve() {
    Solution s;
    cout << s.maxPathSum(construct_tree({ -3 })) << endl;
    cout << s.maxPathSum(construct_tree({ 1, 2, 3 })) << endl;
    cout << s.maxPathSum(construct_tree({ -10, 9, 20, TREE_NULL, TREE_NULL, 15, 7 })) << endl;
}

#endif // TTLEETCODE_Q124_BINARY_TREE_MAXIMUM_PATH_SUM_H