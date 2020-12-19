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
    while (root != nullptr || !s.empty()) {
      if (root != nullptr) {
        s.push(root);
        root = root->left;
      } else {
        root = s.top();
        s.pop();
        ret.push_back(root->val);
        root = root->right;
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

  static vector<int> preorder_recursive(TreeNode *root) {
    vector<int> ret;
    preorder_recursive_fun(root, ret);
    return ret;
  }

  static vector<int> preorder_no_recursive(TreeNode *root) {
    vector<int> ret;
    stack<TreeNode *> s;
    while (root != nullptr || !s.empty()) {
      if (root != nullptr) {
        ret.push_back(root->val);
        if (root->right != nullptr)
          s.push(root->right);
        root = root->left;
      } else {
        root = s.top();
        s.pop();
      }
    }
    return ret;
  }

  static vector<int> preorder_morris(TreeNode *root) {
    vector<int> ret;
    TreeNode *predecessor = root;
    while (root != nullptr) {
      if (root->left != nullptr) {
        predecessor = root->left;
        while (predecessor->right != nullptr && predecessor->right != root)
          predecessor = predecessor->right;
        if (predecessor->right == nullptr) {
          predecessor->right = root;
          ret.push_back(root->val);
          root = root->left;
        } else {
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

  static vector<int> postorder_recursive(TreeNode *root) {
    vector<int> ret;
    postorder_recursive_fun(root, ret);
    return ret;
  }

  static vector<int> postorder_no_recursive(TreeNode *root) {
    vector<int> ret;
    stack<TreeNode *> s;
    TreeNode *prev = nullptr;
    while (root != nullptr || !s.empty()) {
      if (root != nullptr) {
        s.push(root);
        root = root->left;
      } else {
        root = s.top();
        if (root->right == nullptr || root->right == prev) {
          ret.push_back(root->val);
          s.pop();
          prev = root;
          root = nullptr;
        } else {
          root = root->right;
        }
      }
    }
    return ret;
  }

  static vector<int> postorder_morris(TreeNode *root) {
    vector<int> ret;
    TreeNode *add_node = new TreeNode(0);
    add_node->left = root;
    root = add_node;
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
          predecessor->right = nullptr;
          addpath(ret, root->left);
          root = root->right;
        }
      } else {
        root = root->right;
      }
    }
    delete add_node;
    return ret;
  }

private:
  static void inorder_recursive_fun(TreeNode *node, vector<int> &vec) {
    if (node == nullptr) return;
    inorder_recursive_fun(node->left, vec);
    vec.push_back(node->val);
    inorder_recursive_fun(node->right, vec);
  }

  static void preorder_recursive_fun(TreeNode *node, vector<int> &vec) {
    if (node == nullptr) return;
    vec.push_back(node->val);
    preorder_recursive_fun(node->left, vec);
    preorder_recursive_fun(node->right, vec);
  }

  static void postorder_recursive_fun(TreeNode *node, vector<int> &vec) {
    if (node == nullptr) return;
    postorder_recursive_fun(node->left, vec);
    postorder_recursive_fun(node->right, vec);
    vec.push_back(node->val);
  }

  static void addpath(vector<int> &vec, TreeNode *node) {
    int count = 0;
    while (node != nullptr) {
      ++count;
      vec.push_back(node->val);
      node = node->right;
    }
    reverse(vec.end() - count, vec.end());
  }
};

static void test_traverse(const vector<int64_t> &vec) {
  TreeNode *root = construct_tree(vec);
  display(root);
  cout << "inorder(recursive):\t\t\t";
  display(TreeTraverse::inorder_recursive(root));
  cout << "inorder(no-recursive):\t\t";
  display(TreeTraverse::inorder_no_recursive(root));
  cout << "inorder(morris):\t\t\t";
  display(TreeTraverse::inorder_morris(root));
  cout << "preorder(recursive):\t\t";
  display(TreeTraverse::preorder_recursive(root));
  cout << "preorder(no-recursive):\t\t";
  display(TreeTraverse::preorder_no_recursive(root));
  cout << "preorder(morris):\t\t\t";
  display(TreeTraverse::preorder_morris(root));
  cout << "postorder(recursive):\t\t";
  display(TreeTraverse::postorder_recursive(root));
  cout << "postorder(no-recursive):\t";
  display(TreeTraverse::postorder_no_recursive(root));
  cout << "postorder(morris):\t\t\t";
  display(TreeTraverse::postorder_morris(root));
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
