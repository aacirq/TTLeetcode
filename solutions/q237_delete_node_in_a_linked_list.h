//
// Created by renxin on 2020/12/14.
// Leetcode 237
// 注：思考的时候注意用O(1)的方法。

#ifndef TTLEETCODE_Q237_DELETE_NODE_IN_A_LINKED_LIST_H
#define TTLEETCODE_Q237_DELETE_NODE_IN_A_LINKED_LIST_H

#include "../basic.h"

class Solution {
public:
    void deleteNode(ListNode *node) {
        node->val = node->next->val;
        ListNode *ready_to_delete = node->next;
        node->next = node->next->next;
        delete ready_to_delete;
    }
};

static void solve() {
    Solution s;
    ListNode *head = construct_list({ 0, 1, 2, 3, 4, 5 });
    s.deleteNode(head);
    display(head);
}

#endif // TTLEETCODE_Q237_DELETE_NODE_IN_A_LINKED_LIST_H
