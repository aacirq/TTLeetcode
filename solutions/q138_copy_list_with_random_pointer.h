//
// Created by renxin on 2020/12/15.
// 想到了用hash表的思路(本事是较快的方法)，但是代码实现的不好，导致时间效率不高(引入了太多局部变量，可以直接用hash表变量来进行)
//
// 没想到的思路是空间复杂度较低的方法：
// 下述说明中，{3, 1}表示该节点的val是3，random连接第1个结点(从0开始，-1表示nullptr)
// 在原始链表中每个结点后面都插入一个结点，生成一个长度为2N的链表
// 例如{ {3, 1}, {5, 0}, {7, 1} }，插入后得到{ {3, 2}, {3, -1}, {5, 0}, {5, -1}, {7, 2}, {7, -1} }
// 然后遍历这条链表，利用原来结点之间random的关系依次后移一个，得到如下
// { {3, 2}, {3, 3}, {5, 0}, {5, 1}, {7, 2}, {7, 3} }
// 然后，重组为两个链表
//

#ifndef TTLEETCODE_Q138_COPY_LIST_WITH_RANDOM_POINTER_H
#define TTLEETCODE_Q138_COPY_LIST_WITH_RANDOM_POINTER_H

#include "../basic.h"

// Definition for a Node.(List with random pointer)
class Node {
public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

#if 0

// 时间O(2N)，空间O(N)
class Solution {
public:
  Node* copyRandomList(Node* head) {
    if (head == nullptr) return nullptr;
    unordered_map<Node *, Node *> relation;
    relation[nullptr] = nullptr;
    Node *node = head;
    while (node) {
      relation[node] = new Node(node->val);
      node = node->next;
    }
    node = head;
    while (node) {
      relation[node]->next = relation[node->next];
      relation[node]->random = relation[node->random];
      node = node->next;
    }
    return relation[head];
  }
};

#else

// 时间O(3N)(稍慢点，但是同一个数量级)，空间O(1)
class Solution {
public:
  Node* copyRandomList(Node* head) {
    if (head == nullptr) return nullptr;
    Node *node = head;
    while (node != nullptr) {
      Node *tmp_node = new Node(node->val);
      tmp_node->next = node->next;
      node->next = tmp_node;
      node = tmp_node->next;
    }
    node = head;
    while (node != nullptr) {
      if (node->random != nullptr)
        node->next->random = node->random->next;
      node = node->next->next;
    }
    Node *ret_head = head->next;
    node = head;
    while (node != nullptr) {
      Node *tmp_node = node->next;
      node->next = tmp_node->next;
      if (node->next != nullptr)
        tmp_node->next = node->next->next;
      node = node->next;
    }
    return ret_head;
  }
};

#endif

// construct linked list with random pointer
// construct_list_with_random_pointer({ {1, 1}, {2, -1} })，其中，{i, p}表示该结点val为i，random连接第p个（从0开始，-1表示nullptr）
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

// display linked list with random pointer
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
