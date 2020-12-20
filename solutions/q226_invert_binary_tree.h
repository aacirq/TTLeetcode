//
// Created by renxin on 2020/12/20.
//

#ifndef TTLEETCODE_Q226_INVERT_BINARY_TREE_H
#define TTLEETCODE_Q226_INVERT_BINARY_TREE_H

#include "../basic.h"

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

static void solve() {
    Solution s;
    TreeNode *root = construct_tree({ 4, 2, 7, 1, 3, 6, 9 });
    display(root);
    display(s.invertTree(root));
}

#endif // TTLEETCODE_Q226_INVERT_BINARY_TREE_H
