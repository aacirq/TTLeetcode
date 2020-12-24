//
// Created by renxin on 2020/12/24.
//

#ifndef TTLEETCODE_Q297_SERIALIZE_AND_DESERIALIZE_BINARY_TREE_H
#define TTLEETCODE_Q297_SERIALIZE_AND_DESERIALIZE_BINARY_TREE_H

#include "../basic.h"

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string str;
        if (root == nullptr) return str;
        queue<TreeNode *> q;
        q.push(root);
        str += to_string(root->val);
        bool all_null;
        while (!q.empty()) {
            int sz = q.size();
            all_null = true;
            string tmp_str;
            while (sz--) {
                tmp_str += ",";
                if (q.front()->left != nullptr) {
                    tmp_str += to_string(q.front()->left->val);
                    q.push(q.front()->left);
                    all_null = false;
                } else {
                    tmp_str += "null";
                }
                tmp_str += ",";
                if (q.front()->right != nullptr) {
                    tmp_str += to_string(q.front()->right->val);
                    q.push(q.front()->right);
                    all_null = false;
                } else {
                    tmp_str += "null";
                }
                q.pop();
            }
            if (!all_null) str += tmp_str;
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string &data) {
        if (data.empty()) return nullptr;
        int ind = 0;
        size_t sz = 0;
        queue<TreeNode *> q;
        TreeNode *root;
        root = new TreeNode(stoi(data, &sz));
        q.push(root);
        ind += sz;
        while (ind < data.size()) {
            ++ind;
            if (data[ind] == 'n') {
                q.front()->left = nullptr;
                ind += 4;
            } else {
                q.front()->left = new TreeNode(stoi(data.substr(ind), &sz));
                q.push(q.front()->left);
                ind += sz;
            }

            ++ind;
            if (data[ind] == 'n') {
                q.front()->right = nullptr;
                ind += 4;
            } else {
                q.front()->right = new TreeNode(stoi(data.substr(ind), &sz));
                q.push(q.front()->right);
                ind += sz;
            }
            q.pop();
        }
        return root;
    }
};

static void test_codec(const vector<tree_type> &vec) {
    Codec c;
    TreeNode *root = construct_tree(vec);
    cout << "Original ";
    display(root);
    string str = c.serialize(root);
    cout << "Serialized: " << "\"" << str << "\"" << endl;
    cout << "Deserialized ";
    display(c.deserialize(str));
    cout << endl << endl;
}

static void solve() {
    test_codec({  });
    test_codec({ 1, tree_null, 3, tree_null, tree_null, tree_null, 5 });
    test_codec({ 1, 2, 3, tree_null, tree_null, 4, 5 });
    test_codec({ 1, -2, 3, tree_null, tree_null, -4, 5 });
}

#endif // TTLEETCODE_Q297_SERIALIZE_AND_DESERIALIZE_BINARY_TREE_H
