#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"

// Define TreeNode structure
typedef struct TreeNode
{
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

// Function to create a new tree node
TreeNode *createTreeNode(int data)
{
  TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
  newNode->value = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

// Function to perform pre-order traversal and store values in an array list
ArrayList *walk(TreeNode *node, ArrayList *path)
{
  if (node == NULL)
  {
    return path;
  }

  add_element(path, node->value);

  walk(node->left, path);
  walk(node->right, path);

  return path;
}

// Wrapper function for pre-order traversal
ArrayList *pre_order_search(TreeNode *head)
{
  ArrayList *arr = create_array_list(3);
  return walk(head, arr);
}

// Function to insert a node into the binary tree
TreeNode *insertNode(TreeNode *root, int data)
{
  if (root == NULL)
  {
    return createTreeNode(data);
  }

  if (data < root->value)
  {
    root->left = insertNode(root->left, data);
  }
  else if (data > root->value)
  {
    root->right = insertNode(root->right, data);
  }

  return root;
}

// Function to free the binary tree
void free_tree(TreeNode *root)
{
  if (root == NULL)
  {
    return;
  }

  free_tree(root->left);
  free_tree(root->right);

  free(root);
}

// int main()
// {
//   TreeNode *root = NULL;

//   // Insert nodes into the binary tree
//   root = insertNode(root, 50);
//   insertNode(root, 30);
//   insertNode(root, 20);
//   insertNode(root, 40);
//   insertNode(root, 70);
//   insertNode(root, 60);
//   insertNode(root, 80);

//   // Perform pre-order traversal and print the result
//   printf("Pre-order traversal: ");
//   ArrayList *result = pre_order_search(root);
//   print_array(result);

//   // Free the array list
//   free_array_list(result);

//   // Free the binary tree
//   free_tree(root);

//   return 0;
// }
