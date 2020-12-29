//
// Created by renxin on 2020/12/29.
// 本质上是二叉树的前序遍历
// 有一些提交的代码中如果判断t1和t2中其中一个不为空，另一个为空，就直接将不为空的那一个结点返回回去
// 我不同意这种解法，这种方法虽然快，但是破坏了原先树的结构，如果后面再想释放树的空间，
// 由于没有将之前移走的地址的父节点相应指针设置为空，也没法按照需要来释放原二叉树空间
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
