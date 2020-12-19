//
// Created by renxin on 2020/12/16.
//

#ifndef TTLEETCODE_Q108_CONVERT_SORTED_ARRAY_TO__H
#define TTLEETCODE_Q108_CONVERT_SORTED_ARRAY_TO__H

#include "../basic.h"

class Solution {
public:
  TreeNode *sortedArrayToBST(const vector<int> &nums) {
    return build(nums, 0, nums.size());
  }
private:
  TreeNode *build(const vector<int> &nums, int left, int right) {
    if (left >= right) return nullptr;
    int mid = left + (right - left) / 2;
    TreeNode *node = new TreeNode(nums[mid]);
    node->left = build(nums, left, mid);
    node->right = build(nums, mid + 1, right);
    return node;
  }
};

static void solve() {
  Solution s;
  display(s.sortedArrayToBST({  }));
  display(s.sortedArrayToBST({ 1 }));
  display(s.sortedArrayToBST({-10, -3, 0, 5}));
  display(s.sortedArrayToBST({-10, -3, 0, 5, 9}));
}

#endif //TTLEETCODE_Q108_CONVERT_SORTED_ARRAY_TO__H
