//
// Created by renxin on 2020/12/19.
//

#ifndef TTLEETCODE_BINARY_TREE_TRAVERSE_H
#define TTLEETCODE_BINARY_TREE_TRAVERSE_H

#include "../basic.h"

class TreeTraverse {
public:
  static vector<int> inorder_recursive(TreeNode *root) {
    vector<int> ret;
    inorder_recursive_fun(root, ret);
    return ret;
  }

  static vector<int> inorder_no_recursive(TreeNode *root) {
    vector<int> ret;
    stack<TreeNode *> s;
    TreeNode *node = root;
    while (node != nullptr || !s.empty()) {
      if (node != nullptr) {
        s.push(node);
        node = node->left;
      } else {
        node = s.top();
        s.pop();
        ret.push_back(node->val);
        node = node->right;
      }
    }
    return ret;
  }

  static vector<int> inorder_morris(TreeNode *root) {
    vector<int> ret;
    TreeNode *predecessor = nullptr;
    while (root != nullptr) {
      if (root->left != nullptr) {
        predecessor = root->left;
        while (predecessor->right != nullptr && predecessor->right != root)
          predecessor = predecessor->right;
        if (predecessor->right == nullptr) {
          predecessor->right = root;
          root = root->left;
        } else {
          ret.push_back(root->val);
          predecessor->right = nullptr;
          root = root->right;
        }
      } else {
        ret.push_back(root->val);
        root = root->right;
      }
    }
    return ret;
  }

private:
  static void inorder_recursive_fun(TreeNode *node, vector<int> &vec) {
    if (node == nullptr) return;
    inorder_recursive_fun(node->left, vec);
    vec.push_back(node->val);
    inorder_recursive_fun(node->right, vec);
  }
};

static void test_traverse(const vector<int64_t> &vec) {
  TreeNode *root = construct_tree(vec);
  display(root);
  cout << "inorder(recursive):\t\t";
  display(TreeTraverse::inorder_recursive(root));
  cout << "inorder(no recursive):\t";
  display(TreeTraverse::inorder_no_recursive(root));
  cout << "inorder(morris):\t\t";
  display(TreeTraverse::inorder_morris(root));
  cout << endl;
}

static void solve() {
  test_traverse({  });
  test_traverse({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
  test_traverse({ 1, TREE_NULL, 2, TREE_NULL, TREE_NULL, TREE_NULL, 3 });
  test_traverse({ 1, 2, TREE_NULL, 3 });
  test_traverse({ 1, 2, TREE_NULL, TREE_NULL, 3, TREE_NULL, TREE_NULL, TREE_NULL, TREE_NULL, 4 });
}

#endif // TTLEETCODE_BINARY_TREE_TRAVERSE_H
