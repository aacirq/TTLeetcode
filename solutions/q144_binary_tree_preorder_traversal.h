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
  display(s.preorderTraversal(construct_tree({ 1, TREE_NULL, 2, TREE_NULL, TREE_NULL, TREE_NULL, 3 })));
  display(s.preorderTraversal(construct_tree({ 1, 2, TREE_NULL, 3 })));
  display(s.preorderTraversal(construct_tree({ 1, 2, TREE_NULL, TREE_NULL, 3, TREE_NULL, TREE_NULL, TREE_NULL, TREE_NULL, 4 })));
}

#endif //TTLEETCODE_Q144_BINARY_TREE_PREORDER_TRAVERSAL_H
