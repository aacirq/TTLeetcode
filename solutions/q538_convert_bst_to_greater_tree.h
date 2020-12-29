//
// Created by renxin on 2020/12/29.
//

#ifndef TTLEETCODE_Q538_CONVERT_BST_TO_GREATER_TREE_H
#define TTLEETCODE_Q538_CONVERT_BST_TO_GREATER_TREE_H

#include "../basic.h"

class Solution {
public:
    TreeNode* convertBST(TreeNode *root) {
        int to_add = 0;
        traverse(root, to_add);
        return root;
    }

private:
    void traverse(TreeNode *node, int &to_add) {
        if (node == nullptr) return;
        traverse(node->right, to_add);
        node->val += to_add;
        to_add = node->val;
        traverse(node->left, to_add);
    }
};

static void solve() {
    TreeNode *root = construct_tree({ 4,1,6,0,2,5,7,tree_null,tree_null,tree_null,3,tree_null,tree_null,tree_null,8 });
    Solution s;
    display(s.convertBST(root));
}

#endif // TTLEETCODE_Q538_CONVERT_BST_TO_GREATER_TREE_H
