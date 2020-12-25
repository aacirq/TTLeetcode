//
// Created by renxin on 2020/12/24.
// 最开始用的层序的方法(利用了Leetcode上对二叉树序列化的规则)，但是很慢
// 又改用先序的方法，不知道为什么仍然很慢。（beats 15.78%）
//
// !!! 找到原因了，问题处在调用substr上，最初的调用进击提供开始位置(第一个参数)，没有提供选取字符数量(第二个参数)
// !!! TODO: 目前还不知道substr的原理，暂时还分析不了为什么会慢
// 修改后beats 99.5%
//
// 然后又发现了一个很有趣的思路，这个实现中利用字符串保存内存的状态
// 对于每个结点，先用一个字符表示是否为nullptr，
//    如果是，将这个字符设置为0
//    如果不是，将这个字符设置为0xff，然后再跟上sizeof(int)个字符，并将剩下的分别字符设置为node->val的内存的状态
//    例如：如果node->val是0x01020304，那么会有5个字符存储其状态，即[0xff 0x01 0x02 0x03 0x04]
// 解析时，如果前面的标志字符是0，那么这个结点就是nullptr，如果不是0，重组后续sizeof(int)个字符
//    例如，再上面的例子中，标志位不是0，然后重组后面的字节，为0x01020304，得到新的node->val的值
// !!!但这个方法适用性差，只能在一台机器中使用，由于不同机器上对整数内存中排序方式不同，例如大端法和小端法
//    如果在大端法的机器上序列化，再去小端法的机器上反序列化，无法得到正确结果
//    同样的，在int类型所占内存长度不同的机器上传输时，也会存在解析失败的问题
// !!!而且就这个问题而言，利用了string类型，如果直接利用地址修改字符串，所以要依次修改每个字符，设定为解析的地址中的值
//    极易出错，而且效率也没有提高。
//

#ifndef TTLEETCODE_Q297_SERIALIZE_AND_DESERIALIZE_BINARY_TREE_H
#define TTLEETCODE_Q297_SERIALIZE_AND_DESERIALIZE_BINARY_TREE_H

#include "../basic.h"

#if 1
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
        if (str[ind] == '#') {
            ++ind;
            return nullptr;
        }
        size_t k = ind;
        while (str[ind] != ',') ++ind;
        TreeNode *node = new TreeNode(stoi(str.substr(k, ind - k)));
        node->left = deserialize_fun(str, ind);
        node->right = deserialize_fun(str, ind);
        return node;
    }
};

#else

// 解析内存的方法，能解决这个问题，但适用性不足，写着玩的:)
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
        if (node == nullptr) {
            str += (char)0;
            return;
        }
        size_t sz = str.size();
        str.resize(sz + sizeof(int) / sizeof(char) + 1);
        str[sz] = (char)0xff;
        for (int i = 0; i < sizeof(int) / sizeof(char); ++i) {
            str[sz + i + 1] = *((char *)&(node->val) + i);
        }
        serialize_fun(node->left, str);
        serialize_fun(node->right, str);
    }

    TreeNode *deserialize_fun(string &str, size_t &ind) {
        if (str[ind++] == (char)0) return nullptr;
        auto *node = new TreeNode(0);
        for (int i = 0; i < sizeof(int) / sizeof(char); ++i) {
            *((char *)&(node->val) + i) = str[ind + i];
        }
        ind += sizeof(int) / sizeof(char);
        node->left = deserialize_fun(str, ind);
        node->right = deserialize_fun(str, ind);
        return node;
    }
};

#endif

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
    test_codec({ 1, tree_null, 3, tree_null, 5 });
    test_codec({ 1, 2, 3, tree_null, tree_null, 4, 5 });
    test_codec({ 1, -2, 3, tree_null, tree_null, -4, 5 });
}

#endif // TTLEETCODE_Q297_SERIALIZE_AND_DESERIALIZE_BINARY_TREE_H
