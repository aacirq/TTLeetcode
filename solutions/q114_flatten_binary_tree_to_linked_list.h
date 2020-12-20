//
// Created by renxin on 2020/12/20.
// 分析：按照题目给出的例子，是按照二叉树先序遍历的顺序连接结点的，并利用right指针作为链表的next指针
//

#ifndef TTLEETCODE_Q114_FLATTEN_BINARY_TREE_TO_LINKED_LIST_H
#define TTLEETCODE_Q114_FLATTEN_BINARY_TREE_TO_LINKED_LIST_H

#include "../basic.h"

class Solution {
public:
    void flatten(TreeNode *root) {
        vector<TreeNode *> vec;
        fun(root, vec);
        for (int i = 1; i < vec.size(); ++i) {
            vec[i - 1]->left = nullptr;
            vec[i - 1]->right = vec[i];
        }
    }

private:
    void fun(TreeNode *node, vector<TreeNode *> &vec) {
        if (node == nullptr) return;
        vec.push_back(node);
        fun(node->left, vec);
        fun(node->right, vec);
    }
};

static void test_flatten(const vector<int64_t> &vec) {
    Solution s;
    TreeNode *root = construct_tree(vec);
    s.flatten(root);
    display(root);
}

static void solve() {
    test_flatten({ 1, 2, 5, 3, 4, tree_null, 6 });
    test_flatten({ 1, 2, 5, 3, 4, 11, 6, 7, 8, 9, 10 });
}

#endif // TTLEETCODE_Q114_FLATTEN_BINARY_TREE_TO_LINKED_LIST_H
