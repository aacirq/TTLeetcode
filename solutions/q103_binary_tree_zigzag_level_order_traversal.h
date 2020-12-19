//
// Created by renxin on 2020/12/15.
// 方法1：用一个变量表示奇数层和偶数层，先按照层序遍历的方式，然后偶数层翻转（这种方法在翻转上花费一些时间）
// *方法2：可以开vector的时候直接开好相应大小，然后奇数层顺着填，偶数层逆着填
//

#ifndef TTLEETCODE_Q103_BINARY_TREE_ZIGZAG_LEVEL_ORDER_TRAVERSAL_H
#define TTLEETCODE_Q103_BINARY_TREE_ZIGZAG_LEVEL_ORDER_TRAVERSAL_H

#include "../basic.h"

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> ret;
        if (root == nullptr) return ret;
        queue<TreeNode *> s;
        s.push(root);
        bool inorder = true;
        while (!s.empty()) {
            int sz = s.size();
            vector<int> line(sz);
            int b, e, step;
            if (inorder) { b = 0;      e = sz; step = 1; }
            else         { b = sz - 1; e = -1; step = -1; }
            for (int i = b; i != e; i += step) {
                line[i] = s.front()->val;
                if (s.front()->left)  s.push(s.front()->left);
                if (s.front()->right) s.push(s.front()->right);
                s.pop();
            }
            inorder = !inorder;
            ret.push_back(line);
        }
        return ret;
    }
};

static void solve() {
    Solution s;
    display(s.zigzagLevelOrder(construct_tree({  })));
    display(s.zigzagLevelOrder(construct_tree({ 1 })));
    display(s.zigzagLevelOrder(construct_tree({ 1, TREE_NULL, 3, TREE_NULL, TREE_NULL, 6, 7 })));
    display(s.zigzagLevelOrder(construct_tree({ 1, TREE_NULL, 3, TREE_NULL, TREE_NULL, 6})));
    display(s.zigzagLevelOrder(construct_tree({ 3, 9, 20, TREE_NULL, TREE_NULL, 15, 7 })));
}

#endif // TTLEETCODE_Q103_BINARY_TREE_ZIGZAG_LEVEL_ORDER_TRAVERSAL_H
