#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "dynamic_array.h"

// Define TreeNode structure
typedef struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function prototypes
TreeNode *createTreeNode(int data);
ArrayList *walk(TreeNode *node, ArrayList *path);
ArrayList *pre_order_search(TreeNode *head);
TreeNode *insertNode(TreeNode *root, int data);
void free_tree(TreeNode *root);

#endif /* BINARY_TREE_H */
