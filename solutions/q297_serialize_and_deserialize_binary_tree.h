//
// Created by renxin on 2020/12/24.
// 最开始用的层序的方法(利用了Leetcode上对二叉树序列化的规则)，但是很慢
// 又改用先序的方法，不知道为什么仍然很慢。（beats 15.78%）
//
// !!! 找到原因了，问题处在调用substr上，最初的调用进击提供开始位置(第一个参数)，没有提供选取字符数量(第二个参数)
// !!! TODO: 目前还不知道substr的原理，暂时还分析不了为什么会慢
// 修改后beats 99.5%
//

#ifndef TTLEETCODE_Q297_SERIALIZE_AND_DESERIALIZE_BINARY_TREE_H
#define TTLEETCODE_Q297_SERIALIZE_AND_DESERIALIZE_BINARY_TREE_H

#include "../basic.h"

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string str;
        serialize_fun(root, str);
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        size_t ind = 0;
        return deserialize_fun(data, ind);
    }

private:
    void serialize_fun(TreeNode *node, string &str) {
        str += ',';
        if (node == nullptr) {
            str += '#';
            return;
        }
        str += to_string(node->val);
        serialize_fun(node->left, str);
        serialize_fun(node->right, str);
    }

    TreeNode *deserialize_fun(string &str, size_t &ind) {
        if (str[ind] == ',') ++ind;
        if (str[ind] == '#') { ++ind; return nullptr; }
        size_t k = ind;
        while (str[ind] != ',') ++ind;
        TreeNode *node = new TreeNode(stoi(str.substr(k, ind - k)));
        node->left = deserialize_fun(str, ind);
        node->right = deserialize_fun(str, ind);
        return node;
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
