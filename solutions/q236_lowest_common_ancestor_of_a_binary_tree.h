//
// Created by renxin on 2020/12/22.
// 由于刚开始做的时候老是想着不在类内加成员变量，所以代码一直组织不好
// 然后看了官方题解的方法，才加上成员变量，最终才实现好
//

#ifndef TTLEETCODE_Q236_LOWEST_COMMON_ANCESTOR_OF_A_BINARY_TREE_H
#define TTLEETCODE_Q236_LOWEST_COMMON_ANCESTOR_OF_A_BINARY_TREE_H

#include "../basic.h"

class Solution {
private:
    TreeNode *ans = nullptr;

public:
    TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        fun(root, p, q);
        return ans;
    }

private:
    bool fun(TreeNode *node, TreeNode *p, TreeNode *q) {
        if (node == nullptr) return false;
        bool b_left = fun(node->left, p, q);
        bool b_right = fun(node->right, p, q);
        if ((b_left && b_right) || ((node == p || node == q) && (b_left || b_right) )) {
            ans = node;
            return true;
        }
        return b_left || b_right || (node == p) || node == q;
    }
};

static void solve() {
    Solution s1;
    TreeNode *root, *node;
    root = construct_tree({ 3, 5, 1, 6, 2, 0, 8, tree_null, tree_null, 7, 4 });
    display(root);
    cout << endl;
    node = s1.lowestCommonAncestor(root, root->left, root->right);
    cout << node->val << endl;

    Solution s2;
    root = construct_tree({ 3, 5, 1, 6, 2, 0, 8, tree_null, tree_null, 7, 4 });
    node = s2.lowestCommonAncestor(root, root->left, root->left->right->right);
    cout << node->val << endl;

    Solution s3;
    root = construct_tree({ 1, 2 });
    cout << endl;
    display(root);
    cout << endl;
    node = s3.lowestCommonAncestor(root, root, root->left);
    cout << node->val << endl;
}

#endif // TTLEETCODE_Q236_LOWEST_COMMON_ANCESTOR_OF_A_BINARY_TREE_H
