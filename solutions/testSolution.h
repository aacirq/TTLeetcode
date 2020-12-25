//
// Created by renxi on 2020/11/30.
// 测试刷题框架 或 临时写刷题的代码
// 记录问题
//

#ifndef TTLEETCODE_TESTSOLUTION_H
#define TTLEETCODE_TESTSOLUTION_H

// 1. 为什么去掉../basic.h -> <construct_list / display>，以及此文件中的solve的static就会显示重复定义 [与.o文件中的函数定义重复了，没彻底理解为什么，还需要进一步结合make查和理解]
// TODO(RenXin): 2. 每次需要修改../main_include中include的题目文件才能正常进行，有没有更好的方式
// TODO(TenXin): 3. 现在会编译项目中所有的文件，修改CMakeLists.txt选择性的编译，例如只编译正在做的题目的__Solution.cpp

#include "../basic.h"

static void solve() {
    display(construct_tree({  }));
    display(construct_tree({ 1 }));
    display(construct_tree({ 1, 2, tree_null, 3, tree_null, 4 }));
    display(construct_tree({ 1, tree_null, 2, tree_null, 3 }));
    display(construct_tree({ 1, 2, 3, tree_null, 4, 5 }));
}

#endif