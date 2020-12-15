//
// Created by renxin on 2020/12/14.
// NOTE: 实现循环和重连链表时，利用奇数结点(odd_node)和偶数结点(even_node)来进行，循环条件也是利用这两个结点；
//       如果直接利用head逐个往后进行迭代，只利用奇数结点(odd_node)和偶数结点(even_node)来进行重连链表，代码会很复杂，不优雅。
//       以后注意要先思考怎么实现比较好，再着手写。思考很重要！！！
// 自己的问题：一直想着用head来进行索引，没有习惯用odd_note和even_node来索引。
//

#ifndef TTLEETCODE_Q328_ODD_EVEN_LINKED_LIST_H
#define TTLEETCODE_Q328_ODD_EVEN_LINKED_LIST_H

#include "../basic.h"

class Solution {
public:
  ListNode* oddEvenList(ListNode *head) {
    if (!head) return nullptr;
    ListNode *odd_node  = head;
    ListNode *even_head = head->next;
    ListNode *even_node = even_head;
    while (even_node && even_node->next) {
      odd_node->next = even_node->next;
      odd_node = odd_node->next;
      even_node->next = odd_node->next;
      even_node = even_node->next;
    }
    odd_node->next = even_head;
    return head;
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
