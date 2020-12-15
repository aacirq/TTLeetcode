//
// Created by renxin on 2020/12/15.
//

#ifndef TTLEETCODE_Q138_COPY_LIST_WITH_RANDOM_POINTER_H
#define TTLEETCODE_Q138_COPY_LIST_WITH_RANDOM_POINTER_H

#include "../basic.h"

#if 1

class Solution {
public:
  Node* copyRandomList(Node* head) {
    unordered_map<Node *, Node *> relation;
    Node *ret_head = new Node(0);
    Node *ret_node = ret_head;
    Node *node = head;
    while (node) {
      Node *tmp_node = new Node(node->val);
      relation[node] = tmp_node;
      ret_node->next = tmp_node;
      ret_node = tmp_node;
      node = node->next;
    }
    node = head;
    ret_node = ret_head->next;
    while (node) {
      if (node->random)
        ret_node->random = relation[node->random];
      node = node->next;
      ret_node = ret_node->next;
    }
    ret_node = ret_head;
    ret_head = ret_head->next;
    delete ret_node;
    return ret_head;
  }
};

#else

class Solution {
public:
  Node* copyRandomList(Node* head) {

  }
};

#endif

static Node *construct_list_with_random_pointer(const vector<vector<int>> &vec) {
  if (vec.empty()) return nullptr;
  vector<Node *> node_vec;
  for (int i = 0; i < vec.size(); ++i) {
    node_vec.push_back(new Node(vec[i][0]));
    if (i > 0)
      node_vec[i - 1]->next = node_vec[i];
  }
  for (int i = 0; i < vec.size(); ++i) {
    if (vec[i][1] != -1)
      node_vec[i]->random = node_vec[vec[i][1]];
  }
  return node_vec[0];
}

static void display(Node *head) {
  cout << "List with random pointer:" << endl;
  if (!head) cout << "      no node" << endl;
  while (head) {
    printf("%10x %5d   ", head, head->val);
    if (head->random)
      printf("%x\n", head->random);
    else
      printf("null\n");
    head = head->next;
  }
}

static void solve() {
  Solution s;
  cout << "=== CASE 1 ===" << endl;
  Node *head1 = construct_list_with_random_pointer({ {7, -1}, {13, 0}, {11, 4}, {10, 2}, {1, 0} });
  display(head1);
  display(s.copyRandomList(head1));

  cout << "=== CASE 2 ===" << endl;
  Node *head2 = construct_list_with_random_pointer({ {1, 1}, {2, 1} });
  display(head2);
  display(s.copyRandomList(head2));

  cout << "=== CASE 3 ===" << endl;
  Node *head3 = construct_list_with_random_pointer({ {3, -1}, {3, 0}, {3, -1} });
  display(head3);
  display(s.copyRandomList(head3));

  cout << "=== CASE 4 ===" << endl;
  Node *head4 = construct_list_with_random_pointer({ });
  display(head4);
  display(s.copyRandomList(head4));
}

#endif // TTLEETCODE_Q138_COPY_LIST_WITH_RANDOM_POINTER_H
