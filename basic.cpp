//
// Created by renxi on 2020/12/5.
//

#include "basic.h"

// create List according to a vector<int>
// 可以直接用initiallizer_list，即construct_list({ 1, 2, 3 })
ListNode *construct_list(const std::vector<int> &vec) {
  ListNode *head = new ListNode();
  ListNode *node = head;
  for (auto itr = vec.begin(), itr_e = vec.end(); itr != itr_e; ++itr) {
    node->next = new ListNode(*itr);
    node = node->next;
  }
  node = head;
  head = head->next;
  delete node;
  return head;
}

// display list
void display(const ListNode *node) {
  cout << "List: ";
  if (!node) {
    cout << "null" << endl;
    return;
  }
  while(node->next) {
    cout << node->val << " -> ";
    node = node->next;
  }
  cout << node->val << endl;
}

// display vector
void display(const std::vector<int> &vec) {
  cout << "Vector (" << vec.size() << "): [ ";
  auto itr = vec.begin(), itr_e = vec.end();
  if (itr != itr_e) {
    cout << *itr;
    for (++itr; itr != itr_e; ++itr)
      cout << ", " << *itr;
  }
  cout << " ]" << endl;
}