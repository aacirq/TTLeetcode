//
// Created by renxin on 2020/12/29.
// 想到了双递归的方法，但是这种方法比较慢，O(N^2)
// 更快的方法是利用前缀和+回溯的方法
// 前缀和指：从root结点到当前结点的一条路上所有结点val相加的值（包括当前结点）
// 假设当前结点的前缀和是Na，目标值是target，如果在这条路径上的这个结点之前，存在n个结点的前缀和是Na-target
//     那么这条路径上就有n条path的和是target
// 例如，一条路径为[1, -2, 1, -1]，前缀和分别为[0, 1, -1, 0, -1]（第一个0是指没有元素时的前缀和），target为-1
//     那么，对于第一个元素，Na - target =  1 - (-1) = 2，前缀和中没有相等的
//          对于第二个元素，Na - target = -1 - (-1) = 0，前缀和中有一个相等的，表示存在一条可行路径
//          对于第三个元素，Na - target =  0 - (-1) = 1，前缀和中有一个相等的，表示存在一条可行路径
//          对于第四个元素，Na - target = -1 - (-1) = 0，前缀和中有两个相等的，表示存在两条可行路径
//     所以，这条路径中，总共有1 + 1 + 2 = 4条可行的子路径
//

#ifndef TTLEETCODE_Q437_PATH_SUM_III_H
#define TTLEETCODE_Q437_PATH_SUM_III_H

#include "../basic.h"

#if 0

// 双递归-比较慢 O(N^2)
class Solution {
public:
    int pathSum(TreeNode *root, int sum) {
        if (root == nullptr) return 0;
        return dfs_node(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

private:
    int dfs_node(TreeNode *node, int sum) {
        if (node == nullptr) return 0;
        sum -= node->val;
        int tmp = 0;
        if (sum == 0) tmp = 1;
        return tmp + dfs_node(node->left, sum) + dfs_node(node->right, sum);
    }
};

#else

// 前缀和思路 O(N)，真的巧妙
class Solution {
public:
    int pathSum(TreeNode *root, int sum) {
        unordered_map<int, int> m;
        m[0] = 1;
        return dfs(m, root, sum, 0);
    }

private:
    int dfs(unordered_map<int, int> &m, TreeNode *node, int target, int cur) {
        if (node == nullptr) return 0;
        cur += node->val;
        int tmp = 0;
        if (m.count(cur - target) != 0)
            tmp = m[cur - target];
        ++m[cur];
        tmp += dfs(m, node->left, target, cur);
        tmp += dfs(m, node->right, target, cur);
        --m[cur];
        return tmp;
    }
};

#endif

static void solve() {
    Solution s;
    TreeNode *root = construct_tree({ 10, 5, -3, 3, 2, tree_null, 11, 3, -2, tree_null, 1 });
    cout << s.pathSum(root, 8) << endl;

    TreeNode *root2 = construct_tree({ 1, -2, -3, 1, 3, -2, tree_null, -1 });
    cout << s.pathSum(root2, -1) << endl;
}

#endif // TTLEETCODE_Q437_PATH_SUM_III_H
