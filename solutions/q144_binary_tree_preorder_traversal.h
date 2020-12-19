//
// Created by renxin on 2020/12/19.
//

#ifndef TTLEETCODE_Q144_BINARY_TREE_PREORDER_TRAVERSAL_H
#define TTLEETCODE_Q144_BINARY_TREE_PREORDER_TRAVERSAL_H

#include "../basic.h"

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        preorder_recursive_fun(root, ret);
        return ret;
    }

private:
    void preorder_recursive_fun(TreeNode *node, vector<int> &vec) {
        if (node == nullptr) return;
        vec.push_back(node->val);
        preorder_recursive_fun(node->left, vec);
        preorder_recursive_fun(node->right, vec);
    }
};

static void solve() {
    Solution s;

    display(s.preorderTraversal(construct_tree({  })));
    display(s.preorderTraversal(construct_tree({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 })));
    display(s.preorderTraversal(construct_tree({ 1, tree_null, 2, tree_null, tree_null, tree_null, 3 })));
    display(s.preorderTraversal(construct_tree({ 1, 2, tree_null, 3 })));
    display(s.preorderTraversal(construct_tree({ 1, 2, tree_null, tree_null, 3, tree_null, tree_null, tree_null, tree_null, 4 })));
}

#endif //TTLEETCODE_Q144_BINARY_TREE_PREORDER_TRAVERSAL_H
