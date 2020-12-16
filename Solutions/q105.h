//
// Created by renxin on 2020/12/16.
// 思路是对的，但是在实现的时候有两点没想到，导致运行慢
// 1. 没有想到先用unordered_map建立值和inorder序列下标的索引，导致对于每个preorder中的数字，都需要在inorder序列中遍历搜索。
// 2. 一开始的实现中，为了表示pre_ind的改变状态，将其设置为引用，对build_fun函数的每次调用都会将其加一，但这个可以避免掉
//    利用在inorder中找到元素的位置，减去函数执行之前的左边界下标，就是增多的量，避免了一些运算。
//

#ifndef TTLEETCODE_Q105_H
#define TTLEETCODE_Q105_H

#include "../basic.h"

class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    unordered_map<int, int> m;
    for (int i = 0; i < inorder.size(); ++i)
      m[inorder[i]] = i;
    return build_fun(preorder, inorder, 0, 0, preorder.size(), m);
  }
private:
  TreeNode *build_fun(vector<int> &preorder, vector<int> &inorder, int pre_ind, int left, int right, const unordered_map<int, int> &m) {
    if (left >= right) return nullptr;
    TreeNode *node = new TreeNode(preorder[pre_ind]);
    int mid = m.at(preorder[pre_ind]);
    node->left  = build_fun(preorder, inorder, pre_ind + 1, left, mid, m);
    node->right = build_fun(preorder, inorder, pre_ind + mid - left + 1, mid + 1, right, m);
    return node;
  }
};

static void solve() {
  Solution s;
  vector<int> preorder = { 1, 2, 3 };
  vector<int> inorder  = { 2, 3, 1 };
  display(s.buildTree(preorder, inorder));
}

#endif //TTLEETCODE_Q105_H
