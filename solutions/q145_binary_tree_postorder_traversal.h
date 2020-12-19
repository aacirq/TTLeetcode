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
  display(s.postorderTraversal(construct_tree({ 1, TREE_NULL, 2, TREE_NULL, TREE_NULL, TREE_NULL, 3 })));
  display(s.postorderTraversal(construct_tree({ 1, 2, TREE_NULL, 3 })));
  display(s.postorderTraversal(construct_tree({ 1, 2, TREE_NULL, TREE_NULL, 3, TREE_NULL, TREE_NULL, TREE_NULL, TREE_NULL, 4 })));
}

#endif //TTLEETCODE_Q145_BINARY_TREE_POSTORDER_TRAVERSAL_H
