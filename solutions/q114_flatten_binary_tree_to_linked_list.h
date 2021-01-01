//
// Created by renxin on 2020/12/20.
// 分析：利用后序遍历，先处理左右两个子树为链表，
//      然后操作指针将[当前结点]、[左子树构成的链表]、[右子树构成的链表]三部分合并
//

#ifndef TTLEETCODE_Q114_FLATTEN_BINARY_TREE_TO_LINKED_LIST_H
#define TTLEETCODE_Q114_FLATTEN_BINARY_TREE_TO_LINKED_LIST_H

#include "../basic.h"

// use no extra vector
class Solution {
public:
    void flatten(TreeNode *root) {
        if (root == nullptr) return;
        flatten(root->left);
        flatten(root->right);
        if (root->left != nullptr) {
            TreeNode *tmp = root->left;
            while(tmp->right != nullptr) tmp = tmp->right;
            tmp->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
    }
};

static void print_flatten_tree(TreeNode *node) {
    if (node == nullptr) return;
    else cout << node->val;
    while (node->right != nullptr) {
        node = node->right;
        cout << " -> " << node->val;
    }
}

static void test_flatten(const vector<int64_t> &vec) {
    Solution s;
    TreeNode *root = construct_tree(vec);
    s.flatten(root);
    display(root);
    cout << "Flatten tree: ";
    print_flatten_tree(root);
    cout << endl << endl;
}

static void solve() {
    test_flatten({ 1, 2, 5, 3, 4, tree_null, 6 });
    cout << "Correct answer: 1 -> 2 -> 3 -> 4 -> 5 -> 6" << endl;
    test_flatten({ 1, 2, 5, 3, 4, 11, 6, 7, 8, 9, 10 });
    cout << "Correct answer: 1 -> 2 -> 3 -> 7 -> 8 -> 4 -> 9 -> 10 -> 5 -> 11 -> 6" << endl;
}

#endif // TTLEETCODE_Q114_FLATTEN_BINARY_TREE_TO_LINKED_LIST_H
