//
// Created by renxin on 2020/12/28.
// 将每一个结点分成两种情况讨论，即[包含当前结点的最大值]和[不包含当前结点的最大值]
// 方法1：利用两个unordered_max<TreeNode *, int> f, g.
//       f记录包含node的最大值，g记录不包含node的最大值，这样在更新一个node的时候
//       f[node] = node->val + g[node->left] + g[node->right];
//       g[node] = max(f[node->left], g[node->left]) + max(f[node->right], g[node->right]);
//       所以整体上，对于二叉树是后序遍历的，因为首先要知道node->left以及node->right的信息，然后更新当前node的信息。
// 方法2（优化）：
//       方法1耗费内存，而且对于每个node的两个值，都只是暂时利用一次，用完就扔，所以可以考虑用pair<int, int>;
//       每个pair的first值记录[包含当前结点的最大值]，second记录[不包含当前结点的最大值]
//       利用left变量记录node->left的信息，right变量记录node->right的信息，ret记录node的信息，则
//       ret.first = node->val + left.second + right.second;
//       ret.second = max(left.first, left.second) + max(right.first, right.second);
//       整体上也是后序遍历，先获取left和right变量才能计算ret变量。
//

#ifndef TTLEETCODE_Q337_HOUSE_ROBBER_III_H
#define TTLEETCODE_Q337_HOUSE_ROBBER_III_H

#include "../basic.h"

class Solution {
public:
    int rob(TreeNode *root) {
        auto ret = dfs(root);
        return max(ret.first, ret.second);
    }

private:
    pair<int, int> dfs(TreeNode *node) {
        if (node == nullptr) return make_pair<int, int>(0, 0);
        auto left = dfs(node->left), right = dfs(node->right);
        pair<int, int> ret;
        ret.first = node->val + left.second + right.second;
        ret.second = max(left.first, left.second) + max(right.first, right.second);
        return ret;
    }
};

static void solve() {
    Solution s;
    cout << s.rob(construct_tree({ 3, 2, 3, tree_null, 3, tree_null, 1 })) << endl;
    cout << s.rob(construct_tree({ 3, 4, 5, 1, 3, tree_null, 1 })) << endl;
}

#endif // TTLEETCODE_Q337_HOUSE_ROBBER_III_H
