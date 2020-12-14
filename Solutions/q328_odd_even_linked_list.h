//
// Created by renxin on 2020/12/14.
//

#ifndef TTLEETCODE_Q328_ODD_EVEN_LINKED_LIST_H
#define TTLEETCODE_Q328_ODD_EVEN_LINKED_LIST_H

#include "../basic.h"

class Solution {
public:
  ListNode* oddEvenList(ListNode *head) {
    if (!head) return nullptr;
    ListNode *odd_head  = head;
    ListNode *odd_node  = odd_head;
    head = head->next;
    ListNode *even_head = head;
    ListNode *even_node = even_head;
    while (head) {
      if (head->next) {
        odd_node->next = head->next;
        odd_node = odd_node->next;
      }
      head = head->next;
      if (head) {
        even_node->next = head->next;
        even_node = even_node->next;
        head = head->next;
      }
    }
    odd_node->next = even_head;
    if (even_node)
      even_node->next = nullptr;
    return odd_head;
  }
};

static void solve() {
  Solution s;
  display(s.oddEvenList(nullptr));
  display(s.oddEvenList(construct_list({ 1 })));
  display(s.oddEvenList(construct_list({ 1, 2 })));
  display(s.oddEvenList(construct_list({ 1, 2, 3 })));
  display(s.oddEvenList(construct_list({ 1, 2, 3, 4 })));
  display(s.oddEvenList(construct_list({ 1, 2, 3, 4, 5 })));
  display(s.oddEvenList(construct_list({ 1, 2, 3, 4, 5, 6 })));
  display(s.oddEvenList(construct_list({ 2, 1, 3, 5, 6, 4, 7 })));
}

#endif //TTLEETCODE_Q328_ODD_EVEN_LINKED_LIST_H
