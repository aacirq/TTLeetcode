#ifndef TTLEETCODE_BASIC_H
#define TTLEETCODE_BASIC_H

#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

#define TREE_NULL INT64_MAX

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// create List according to a vector<int>
// 可以直接用initiallizer_list，即construct_list({ 1, 2, 3 })
ListNode *construct_list(const std::vector<int> &vec);

// create Binary Tree according to vector<int64_t>
//   this vec is level order of tree (TREE_NULL means no node in there)
// For example: { 3, 9, 20, TREE_NULL, TREE_NULL, 15, 7 }
//                3
//               / \
//              9  20
//                /  \
//               15   7
// vec is legal, which means than case like { TREE_NULL, TREE_NULL }(illegal) will not exsit
TreeNode *construct_tree(const std::vector<int64_t> &vec);

// display list
void display(const ListNode *node);

// display vector
void display(const std::vector<int> &vec);

// display vector of vector
void display(const std::vector<std::vector<int>> &vec);

// display binary tree
void display(TreeNode *root);

#endif // TTLEETCODE_BASIC_H