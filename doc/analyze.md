# 各种题型总结和分析

到目前，刷题主要是根据**[LeetCode热题HOT 100](https://leetcode-cn.com/problemset/all/?listId=2cktkvj)**以及**[LeetCode精选TOP面试题](https://leetcode-cn.com/problemset/all/?listId=2ckc81c)**两个列表，同时加入少数不在这两个列表中但是相关的题目，在题号后面加上了**(*)**标志

## 缩写说明

| 缩写 | 全称                | 中文       |
| ---- | ------------------- | ---------- |
| BST  | Binary Search Tree  | 二叉搜索树 |
| DP   | Dynamic Programming | 动态规划   |

## 树

备注一栏标记“*****”符号的是指在表格后有对于这个题目更详细的说明，有的是说明题目本身，有的说明标签的原因等。

| 题号   | 题目                                                      | 考查内容(标签)               | 备注 |
| ------ | --------------------------------------------------------- | ---------------------------- | ---- |
| 94     | Binary Tree Inorder Traversal                             | 中序遍历                     |      |
| 98     | Validate Binary Search Tree                               | BST-概念、遍历               | *    |
| 101    | Symmetric Tree                                            | 先序遍历(变体)               | *    |
| 102    | Binary Tree Level Order Traversal                         | 层序遍历                     |      |
| 103    | Binary Tree Zigzag Level Order Traversal                  | 层序遍历                     |      |
| 104    | Maximum Depth of Binary Tree                              | 后序遍历                     |      |
| 105    | Construct Binary Tree from Preorder and Inorder Traversal | 重建(已知先序中序)、先序遍历 | *    |
| 108    | Convert Sorted Array to Binary Search Tree                | BST-概念、重建(已知有序序列) |      |
| 112(*) | Path Sum                                                  | 先序遍历                     |      |
| 113(*) | Path Sum II                                               | 先序遍历                     |      |
| 114    | Flatten Binary Tree to Linked List                        | 后序遍历                     |      |
| 116    | Populating Next Right Pointers in Each Node               | 后序遍历、灵活应用           | *    |
| 124    | Binary Tree Maximum Path Sum                              | 后序遍历                     |      |
| 144(*) | Binary Tree Preorder Traversal                            | 先序遍历                     |      |
| 145(*) | Binary Tree Postorder Traversal                           | 后序遍历                     |      |
| 226    | Invert Binary Tree                                        | 先序遍历                     |      |
| 230    | Kth Smallest Element in a BST                             | 中序遍历                     |      |
| 236    | Lowest Common Ancestor of a Binary Tree                   | 后序遍历                     |      |
| 297    | Serialize and Deserialize Binary Tree                     | 遍历、重建(已知先序结果)     | *    |
| 437    | Path Sum III                                              | 先序遍历、前缀和             | *    |
| 538    | Convert BST to Greater Tree                               | 中序遍历(变体)               | *    |
| 543    | Diameter of Binary Tree                                   | 后序遍历                     | *    |
| 617    | Merge Two Binary Trees                                    | 先序遍历                     |      |

注：有些题目被分到**树**的组里面，但是在我的角度上，这些题目的重点不在树，只是将树作为表示的结构，列举出来

| 题号 | 题目                       | 真正重点 |
| ---- | -------------------------- | -------- |
| 96   | Unique Binary Search Trees | DP、数学 |
| 337  | House Robber III           | DP       |

#### 详细备注：

1. 对于98题，各种遍历方法都能做，而且实现难度相差不大，所以标签只标记了**遍历**，没有指定具体类型。
2. 对于101题，宽泛的说，这是一种先序遍历的方法，大体满足先序遍历的框架，但是是对根节点左右两个子树分别遍历，而且对于右侧结点，遍历顺序是**中→右→左**，所以加了括号标记**变体**。
3. 对于105题，重建时处理结点的顺序实际是对这棵树的先序遍历，所以标记**先序遍历**标签。
4. 对于116题，有两种方法，一种是按照每个结点(子树)的顺序，是后序遍历；另一种方法是利用新建立的`next`指针，一层一层的处理，属于一种灵活的应用。
5. 对于297题，题目中没有规定序列化的规则，所以先序、中序、后序、层序这四种遍历方式都可以，所以只标记**遍历**。
6. 对于538题，宽泛的说，属于中序遍历，但是与一般情况有点差别，对于一个非空结点的遍历的顺序是**右→中→左**，所以加了括号标记**变体**。
7. 从实现的层面来说，在我用的方法中，543题和124题非常相似，只是一个返回一条路径中最大的累积和，一个返回路径的长度。

### 框架

代码框架的内容是用c++来表述的，将代码大量简化了，只保留了最核心的部分。

下述代码中，`do_something(node)`表示对`node`结点进行处理，可以是打印、计算等等。

#### 先序遍历

```c++
void preorder_traverse(TreeNode *node) {
    if (node == nullptr) return;
    do_something(node);
    preorder_traverse(node->left);
    preorder_traverse(node->right);
}
```

#### 中序遍历

```c++
void inorder_traverse(TreeNode *node) {
    if (node == nullptr) return;
    inorder_traverse(node->left);
    do_something(node);
    inorder_traverse(node->right);
}
```

#### 后序遍历

```c++
void postorder_traverse(TreeNode *node) {
    if (node == nullptr) return;
    postorder_traverse(node->left);
    postorder_traverse(node->right);
    do_something(node);
}
```

#### 层序遍历

```c++
void level_order_traverse(TreeNode *root) {
    if (root == nullptr) return;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            do_something(q.front());
            if (q.front()->left != nullptr) q.push(q.front()->left);
            if (q.front()->right != nullptr) q.push(q.front()->right);
            q.pop();
        }
    }
}
```

### 汇总与分析

首先总结一下各个标签出现的频次

| 标签     | 出现次数 |
| -------- | -------- |
| 先序遍历 | 8        |
| 后序遍历 | 7        |
| 中序遍历 | 3        |
| 重建     | 3        |
| BST-概念 | 2        |
| 遍历     | 2        |
| 层序遍历 | 2        |
| 灵活应用 | 1        |
| 前缀和   | 1        |

从这个汇总表格中可以看出，对于树(二叉树)来说，题目中出现最多的就是不同的遍历方式，很多题目就是在二叉树遍历的基础上加上其他的操作完成的。也不难理解，如果要处理二叉树，最起码要把所有的结点都过一遍，也就是要遍历一遍。

在思考二叉树的题目时，要抓住本质，首先思考要怎么样遍历这个二叉树，按照什么顺序，然后再想对每个结点要怎么处理，也就是上文遍历框架中的`do_something(node)`部分，如果这两部分都思考清楚了，问题基本就解决了，其他的都是一些实现细节，需要根据代码来慢慢调试。

