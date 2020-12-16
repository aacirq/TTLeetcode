//
// Created by renxi on 2020/12/16.
// 想到了利用递归的方法，没想到利用已建立next指针的方法
// 对上层已经建立next的一层，根据next走完这一层，这样就可以对下一层进行相应连接
// 其中包括node->left->next = node->right  &  node->right->next = node->next->left
// 注意循环的边界条件
//

#ifndef TTLEETCODE_Q116_POPULATING_NEXT_RIGHT_POINTERS__H
#define TTLEETCODE_Q116_POPULATING_NEXT_RIGHT_POINTERS__H

#include "../basic.h"

class Node {
public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

#if 0

// 利用递归，不是最好的方法
class Solution {
public:
  Node* connect(Node* root) {
    if (root == nullptr || root->left == nullptr) return root;
    connect(root->left);
    connect(root->right);
    Node *node1 = root->left, *node2 = root->right;
    while (node1 != nullptr) {
      node1->next = node2;
      node1 = node1->right;
      node2 = node2->left;
    }
    return root;
  }
};

#else

// 利用已建立的next指针
class Solution {
public:
  Node *connect(Node *root) {
    if (root == nullptr || root->left == nullptr) return root;
    Node *leftmost = root;
    while (leftmost->left != nullptr) {
      Node *node = leftmost;
      while (node != nullptr) {
        node->left->next = node->right;
        if (node->next != nullptr)
          node->right->next = node->next->left;
        node = node->next;
      }
      leftmost = leftmost->left;
    }
    return root;
  }
};

#endif

// TODO: 辅助函数和测试用例

#endif //TTLEETCODE_Q116_POPULATING_NEXT_RIGHT_POINTERS__H
