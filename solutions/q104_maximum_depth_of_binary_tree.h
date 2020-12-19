//
// Created by renxin on 2020/12/16.
//

#ifndef TTLEETCODE_Q104_MAXIMUM_DEPTH_OF_BINARY_TREE_H
#define TTLEETCODE_Q104_MAXIMUM_DEPTH_OF_BINARY_TREE_H

#include "../basic.h"

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

static void solve() {
    Solution s;

    cout << s.maxDepth(construct_tree({  })) << endl;
    cout << s.maxDepth(construct_tree({ 1 })) << endl;
    cout << s.maxDepth(construct_tree({ 1, tree_null, 3, tree_null, tree_null, 6, 7 })) << endl;
    cout << s.maxDepth(construct_tree({ 1, tree_null, 3, tree_null, tree_null, 6})) << endl;
    cout << s.maxDepth(construct_tree({ 3, 9, 20, tree_null, tree_null, 15, 7 })) << endl;
}

#endif // TTLEETCODE_Q104_MAXIMUM_DEPTH_OF_BINARY_TREE_H
