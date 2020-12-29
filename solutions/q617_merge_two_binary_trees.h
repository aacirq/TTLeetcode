//
// Created by renxin on 2020/12/29.
//

#ifndef TTLEETCODE_Q617_MERGE_TWO_BINARY_TREES_H
#define TTLEETCODE_Q617_MERGE_TWO_BINARY_TREES_H

#include "../basic.h"

class Solution {
public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
        if (t1 == nullptr && t2 == nullptr) {
            return nullptr;
        } else {
            auto *node  = new TreeNode(0);
            node->val   = (t1 ? t1->val : 0) + (t2 ? t2->val : 0);
            node->left  = mergeTrees(t1 ? t1->left : nullptr, t2 ? t2->left : nullptr);
            node->right = mergeTrees(t1 ? t1->right : nullptr, t2 ? t2->right : nullptr);
            return node;
        }
    }
};

static void solve() {
    TreeNode *root1 = construct_tree({ 1, 3, 2, 5 });
    TreeNode *root2 = construct_tree({ 2, 1, 3, tree_null, 4, tree_null, 7 });
    display(root1);
    display(root2);
    Solution s;
    display(s.mergeTrees(root1, root2));
}

#endif // TTLEETCODE_Q617_MERGE_TWO_BINARY_TREES_H
