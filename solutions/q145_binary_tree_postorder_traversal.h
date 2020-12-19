//
// Created by renxin on 2020/12/19.
//

#ifndef TTLEETCODE_Q145_BINARY_TREE_POSTORDER_TRAVERSAL_H
#define TTLEETCODE_Q145_BINARY_TREE_POSTORDER_TRAVERSAL_H

#include "../basic.h"

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        postorder_recursive_fun(root, ret);
        return ret;
    }
private:
    void postorder_recursive_fun(TreeNode *node, vector<int> &vec) {
        if (node == nullptr) return;
        postorder_recursive_fun(node->left, vec);
        postorder_recursive_fun(node->right, vec);
        vec.push_back(node->val);
    }
};

static void solve() {
    Solution s;

    display(s.postorderTraversal(construct_tree({  })));
    display(s.postorderTraversal(construct_tree({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 })));
    display(s.postorderTraversal(construct_tree({ 1, tree_null, 2, tree_null, tree_null, tree_null, 3 })));
    display(s.postorderTraversal(construct_tree({ 1, 2, tree_null, 3 })));
    display(s.postorderTraversal(construct_tree({ 1, 2, tree_null, tree_null, 3, tree_null, tree_null, tree_null, tree_null, 4 })));
}

#endif //TTLEETCODE_Q145_BINARY_TREE_POSTORDER_TRAVERSAL_H
