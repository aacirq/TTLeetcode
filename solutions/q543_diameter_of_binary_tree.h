//
// Created by renxin on 2020/12/29.
// 本质上就是求树的高度
//

#ifndef TTLEETCODE_Q543_DIAMETER_OF_BINARY_TREE_H
#define TTLEETCODE_Q543_DIAMETER_OF_BINARY_TREE_H

#include "../basic.h"

class Solution {
public:
    int diameterOfBinaryTree(TreeNode *root) {
        int ret = 0;
        fun(root, ret);
        return ret;
    }

private:
    int fun(TreeNode *node, int &d) {
        if (node == nullptr) return 0;
        int l_height = fun(node->left, d), r_height = fun(node->right, d);
        d = max(d, l_height + r_height);
        return max(l_height, r_height) + 1;
    }
};

static void solve() {
    TreeNode *root = construct_tree({ 1, 2, 3, 4, 5 });
    Solution s;
    cout << s.diameterOfBinaryTree(root) << endl;
}

#endif // TTLEETCODE_Q543_DIAMETER_OF_BINARY_TREE_H
