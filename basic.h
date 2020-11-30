#ifndef TTLEETCODE_BASIC_H
#define TTLEETCODE_BASIC_H

#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*
 * create List according to a vector<int>
 * 可以直接用initiallizer_list，即construct_list({ 1, 2, 3 })
 */
static ListNode *construct_list(const std::vector<int> &vec) {
    ListNode *head = new ListNode();
    ListNode *node = head;
    for(auto itr = vec.begin(), itr_e = vec.end(); itr != itr_e; ++itr) {
        node->next = new ListNode(*itr);
        node = node->next;
    }
    node = head;
    head = head->next;
    delete node;
    return head;
}

/* display list */
static void display(const ListNode *node) {
    cout << "List: ";
    if(!node) {
        cout << "null" << endl;
        return;
    }
    while(node->next) {
        cout << node->val << " -> ";
        node = node->next;
    }
    cout << node->val << endl;
}

/* display vector */
static void display(const std::vector<int> &vec) {
    cout << "Vector (" << vec.size() << "): [ ";
    auto itr = vec.begin(), itr_e = vec.end();
    if(itr != itr_e) {
        cout << *itr;
        for (++itr; itr != itr_e; ++itr)
            cout << ", " << *itr;
    }
    cout << " ]" << endl;
}

#endif //TTLEETCODE_BASIC_H