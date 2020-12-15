//
// Created by renxi on 2020/12/5.
//

#include "basic.h"

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

static void display_a_vecor(const std::vector<int> &vec) {
  cout << "[ ";
  auto itr = vec.begin(), itr_e = vec.end();
  if (itr != itr_e) {
    cout << *itr;
    for (++itr; itr != itr_e; ++itr)
      cout << ", " << *itr;
  }
  cout << " ]";
}

void display(const std::vector<int> &vec) {
  cout << "Vector (" << vec.size() << "): ";
  display_a_vecor(vec);
  cout << endl;
}

void display(const std::vector<std::vector<int>> &vec) {
  cout << "Vector of vector (" << vec.size() << "): [" << endl;
  auto itr = vec.begin(), itr_e = vec.end();
  if (itr != itr_e) {
    cout << "\t";
    display_a_vecor(*itr);
    for (++itr; itr != itr_e; ++itr) {
      cout << "," << endl << "\t";
      display_a_vecor(*itr);
    }
  }
  cout << endl << "]" << endl;
}