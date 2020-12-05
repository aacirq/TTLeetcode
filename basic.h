#ifndef TTLEETCODE_BASIC_H
#define TTLEETCODE_BASIC_H

#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

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

// display list
void display(const ListNode *node);

// display vector
void display(const std::vector<int> &vec);

#endif // TTLEETCODE_BASIC_H