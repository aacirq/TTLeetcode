//
// Created by renxin on 2020/12/15.
//

#ifndef TTLEETCODE_Q103_BINARY_TREE_ZIGZAG_LEVEL_ORDER_TRAVERSAL_H
#define TTLEETCODE_Q103_BINARY_TREE_ZIGZAG_LEVEL_ORDER_TRAVERSAL_H

#include "../basic.h"

class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ret;
    if (root == nullptr) return ret;
    queue<TreeNode *> s;
    s.push(root);
    bool inorder = true;
    while (!s.empty()) {
      int sz = s.size();
      vector<int> line(sz);
      if (inorder) {
        for (int i = 0; i < sz; ++i) {
          line[i] = s.front()->val;
          if (s.front()->left)  s.push(s.front()->left);
          if (s.front()->right) s.push(s.front()->right);
          s.pop();
        }
      } else {
        for (int i = sz - 1; i >= 0; --i) {
          line[i] = s.front()->val;
          if (s.front()->left)  s.push(s.front()->left);
          if (s.front()->right) s.push(s.front()->right);
          s.pop();
        }
      }
      inorder = !inorder;
      ret.push_back(line);
    }
    return ret;
  }
};

static void solve() {
  vector<vector<int>> vec = { {1}, {1, 2}, {1, 2, 3} };
  display(vec);
}

#endif // TTLEETCODE_Q103_BINARY_TREE_ZIGZAG_LEVEL_ORDER_TRAVERSAL_H
