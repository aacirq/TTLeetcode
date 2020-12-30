//
// Created by renxin on 2020/12/30.
//

#ifndef TTLEETCODE_Q102_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_H
#define TTLEETCODE_Q102_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_H

#include "../basic.h"

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> tmp;
            int sz = q.size();
            while(sz--) {
                TreeNode *node = q.front();
                q.pop();
                tmp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};

static void solve() {
    Solution s;
    display(s.levelOrder(construct_tree({ 3, 9, 20, tree_null, tree_null, 15, 7 })));
}

#endif // TTLEETCODE_Q102_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_H
