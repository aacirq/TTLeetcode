//
// Created by renxin on 2020/12/17.
//

#ifndef TTLEETCODE_Q230_KTH_SMALLEST_ELEMENT_IN_A_BST_H
#define TTLEETCODE_Q230_KTH_SMALLEST_ELEMENT_IN_A_BST_H

#include "../basic.h"

# if 0

// 非递归遍历树
class Solution {
public:
  int kthSmallest(TreeNode *root, int k) {
    int num = 0;
    stack<TreeNode *> s;
    TreeNode *node = root;
    while (node || !s.empty()) {
      if (node) {
        s.push(node);
        node = node->left;
      } else {
        node = s.top();
        ++num;
        if (num == k) return node->val;
        s.pop();
        node = node->right;
      }
    }
  }
};

#else

// 递归遍历
class Solution {
public:
  int kthSmallest(TreeNode *root, int k) {
    int count = k, res;
    inorder(root, count, res);
    return res;
  }
private:
  void inorder(TreeNode *node, int &count, int &res) {
    if (node->left != nullptr) inorder(node->left, count, res);
    if (count > 0) {
      --count;
      res = node->val;
    } else {
      return;
    }
    if (node->right != nullptr) inorder(node->right, count, res);
  }
};

#endif

static void solve() {
  Solution s;
  cout << s.kthSmallest(construct_tree({ 3, 1, 4, TREE_NULL, 2 }), 1) << endl;
  cout << s.kthSmallest(construct_tree({ 3, 1, 4, TREE_NULL, 2 }), 2) << endl;
  cout << s.kthSmallest(construct_tree({ 3, 1, 4, TREE_NULL, 2 }), 3) << endl;
  cout << s.kthSmallest(construct_tree({ 3, 1, 4, TREE_NULL, 2 }), 4) << endl;
  cout << s.kthSmallest(construct_tree({ 5, 3, 6, 2, 4, TREE_NULL, TREE_NULL, 1 }), 1) << endl;
  cout << s.kthSmallest(construct_tree({ 5, 3, 6, 2, 4, TREE_NULL, TREE_NULL, 1 }), 2) << endl;
  cout << s.kthSmallest(construct_tree({ 5, 3, 6, 2, 4, TREE_NULL, TREE_NULL, 1 }), 3) << endl;
  cout << s.kthSmallest(construct_tree({ 5, 3, 6, 2, 4, TREE_NULL, TREE_NULL, 1 }), 4) << endl;
  cout << s.kthSmallest(construct_tree({ 5, 3, 6, 2, 4, TREE_NULL, TREE_NULL, 1 }), 5) << endl;
  cout << s.kthSmallest(construct_tree({ 5, 3, 6, 2, 4, TREE_NULL, TREE_NULL, 1 }), 6) << endl;
}

#endif // TTLEETCODE_Q230_KTH_SMALLEST_ELEMENT_IN_A_BST_H
