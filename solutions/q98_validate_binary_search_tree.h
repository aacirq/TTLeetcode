//
// Created by renxin on 2020/12/30.
//

#ifndef TTLEETCODE_Q98_VALIDATE_BINARY_SEARCH_TREE_H
#define TTLEETCODE_Q98_VALIDATE_BINARY_SEARCH_TREE_H

#include "../basic.h"

#define WAY_NUM 2
// 0 - preorder traverse
// 1 - inorder traverse
// 2 - postorder traverse

#if WAY_NUM == 0

// use preorder traverse
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return traverse(root, INT64_MIN, INT64_MAX);
    }

private:
    bool traverse(TreeNode *node, long long lower, long long upper) {
        if (node == nullptr) return true;
        if (node->val <= lower || node->val >= upper)
            return false;
        return traverse(node->left, lower, node->val) && traverse(node->right, node->val, upper);
    }
};

#elif WAY_NUM == 1

// use inorder traverse
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        long long last_value = INT64_MIN;
        bool valid = true;
        traverse(root, last_value, valid);
        return valid;
    }

private:
    void traverse(TreeNode *node, long long &last_value, bool &valid) {
        if (node == nullptr) return;
        traverse(node->left, last_value, valid);
        if (node->val <= last_value) valid = false;
        last_value = node->val;
        traverse(node->right, last_value, valid);
    }
};

#elif WAY_NUM == 2

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        long long last_value = INT64_MAX;
        bool valid = true;
        traverse(root, last_value, valid);
        return valid;
    }

private:
    void traverse(TreeNode *node, long long &last_value, bool &valid) {
        if (node == nullptr) return;
        traverse(node->right, last_value, valid);
        if (node->val >= last_value) valid = false;
        last_value = node->val;
        traverse(node->left, last_value, valid);
    }
};

#endif

static void solve() {
    Solution s;
    cout << "1: " << s.isValidBST(construct_tree({ 2, 1, 3 })) << endl;
    cout << "0: " << s.isValidBST(construct_tree({ 1, 1 })) << endl;
    cout << "0: " << s.isValidBST(construct_tree({ 5, 1, 4, tree_null, tree_null, 3, 6 })) << endl;
    cout << "0: " << s.isValidBST(construct_tree({ 5, 4, 6, tree_null, tree_null, 3, 7 })) << endl;
}

#endif // TTLEETCODE_Q98_VALIDATE_BINARY_SEARCH_TREE_H
