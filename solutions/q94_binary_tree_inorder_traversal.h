//
// Created by renxin on 2020/12/30.
//

#ifndef TTLEETCODE_Q94_BINARY_TREE_INORDER_TRAVERSAL_H
#define TTLEETCODE_Q94_BINARY_TREE_INORDER_TRAVERSAL_H

#include "../basic.h"

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }

private:
    void inorder(TreeNode *node, vector<int> &vec) {
        if(node == nullptr) return;
        inorder(node->left, vec);
        vec.push_back(node->val);
        inorder(node->right, vec);
    }
};

#endif // TTLEETCODE_Q94_BINARY_TREE_INORDER_TRAVERSAL_H
