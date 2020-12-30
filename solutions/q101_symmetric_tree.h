//
// Created by renxin on 2020/12/30.
//

#ifndef TTLEETCODE_Q101_SYMMETRIC_TREE_H
#define TTLEETCODE_Q101_SYMMETRIC_TREE_H

#include "../basic.h"

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        return compareTree(root, root);
    }

private:
    bool compareTree(TreeNode *left, TreeNode *right) {
        if(!left && !right) return true;
        if(!left || !right) return false;
        return left->val == right->val &&
               compareTree(left->left, right->right) &&
               compareTree(left->right, right->left);
    }
};

static void solve() {
    Solution s;
    cout << "1: " << s.isSymmetric(construct_tree({ 1, 2, 2, 3, 4, 4, 3 })) << endl;
    cout << "0: " << s.isSymmetric(construct_tree({ 1, 2, 2, tree_null, 3, tree_null, 3 })) << endl;
}

#endif // TTLEETCODE_Q101_SYMMETRIC_TREE_H
