//
// Created by renxin on 2020/12/28.
// 一定要对叶结点单独判断
//

#ifndef TTLEETCODE_Q112_PATH_SUM_H
#define TTLEETCODE_Q112_PATH_SUM_H

#include "../basic.h"

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == nullptr) return false;
        if (root->left == nullptr && root->right == nullptr)
            return root->val == sum;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

static void solve() {
    Solution s;
    TreeNode *root = construct_tree({ 5, 4, 8, 11, tree_null, 13, 4, 7, 2, tree_null, tree_null, tree_null, 1 });
    display(root);
    cout << s.hasPathSum(nullptr, 0) << endl;
    cout << s.hasPathSum(root, 22) << endl;
    cout << s.hasPathSum(root, 26) << endl;
    cout << s.hasPathSum(root, 27) << endl;
    cout << s.hasPathSum(root, 18) << endl;
    cout << s.hasPathSum(root, 1) << endl;
    cout << s.hasPathSum(root, 27) << endl;
    cout << s.hasPathSum(root, 17) << endl;
    cout << s.hasPathSum(root->right->left, 12-8) << endl;
    cout << s.hasPathSum(root->right->right, 12-8) << endl;
}

#endif // TTLEETCODE_Q112_PATH_SUM_H
