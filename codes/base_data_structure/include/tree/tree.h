#pragma once
#include <iostream>

struct TreeNode
{
    char data;
    TreeNode* left, * right;
};

class BiTree
{
public:
    TreeNode* root;
    BiTree();
    TreeNode* create();
    void pre_order_rec(TreeNode* node);
    void pre_order_non_rec();
    void in_order_rec(TreeNode* node);
    void in_order_non_rec();
    void post_order_rec(TreeNode* node);
    void post_order_non_rec();
    void level_order();
};
