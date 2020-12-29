//
// Created by renxin on 2020/12/29.
// 有思路，但是没写出来
// 最初的实现太注重不使用成员变量
// 以后做题的时候，可以先利用成员变量实现功能，然后再把代码优化
//

#ifndef TTLEETCODE_Q113_PATH_SUM_II_H
#define TTLEETCODE_Q113_PATH_SUM_II_H

#include "../basic.h"

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> ret;
        vector<int> path;
        dfs(root, sum, path, ret);
        return ret;
    }

private:
    void dfs(TreeNode *node, int sum, vector<int> &path, vector<vector<int>> &ret) {
        if (node == nullptr) return;
        sum -= node->val;
        path.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr && sum == 0)
            ret.push_back(path);
        if (node->left != nullptr) dfs(node->left, sum, path, ret);
        if (node->right != nullptr) dfs(node->right, sum, path, ret);
        path.pop_back();
    }
};

static void solve() {
    Solution s;
    TreeNode *root = construct_tree({ 5, 4, 8, 11, tree_null, 13, 4, 7, 2, tree_null, tree_null, 5, 1 });
    display(root);
    display(s.pathSum(root, 22));
}

#endif // TTLEETCODE_Q113_PATH_SUM_II_H
