#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binary_tree.h"
#include "dynamic_array.h"

bool compare_trees(TreeNode *a, TreeNode *b)
{
  if (a == NULL && b == NULL)
  {
    return true;
  }
  if (a == NULL || b == NULL)
  {
    return false;
  }
  if (a->value != b->value)
  {
    return false;
  }
  return compare_trees(a->left, b->left) && compare_trees(a->right, b->right);
}

bool search(TreeNode *curr, int needle)
{
  if (curr == NULL)
  {
    return false;
  }
  if (curr->value == needle)
  {
    return true;
  }
  if (curr->value < needle)
  {
    return search(curr->right, needle);
  }
  else
  {
    return search(curr->left, needle);
  }
}

bool dfs(TreeNode *root, int needle)
{
  return search(root, needle);
}

int main()
{
  TreeNode *root = NULL;

  // Insert nodes into the binary tree
  root = insertNode(root, 50);
  insertNode(root, 30);
  insertNode(root, 20);
  insertNode(root, 40);
  insertNode(root, 70);
  insertNode(root, 60);
  insertNode(root, 80);

  // Perform pre-order traversal
  ArrayList *arr = pre_order_search(root);
  printf("Pre-order traversal: ");
  print_array(arr);

  // Search for a value in the binary tree
  int needle = 60;
  if (dfs(root, needle))
  {
    printf("Found %d in the tree.\n", needle);
  }
  else
  {
    printf("%d not found in the tree.\n", needle);
  }

  // Compare two trees
  TreeNode *another_root = NULL;
  another_root = insertNode(another_root, 50);
  insertNode(another_root, 30);
  insertNode(another_root, 20);
  insertNode(another_root, 40);
  insertNode(another_root, 70);
  insertNode(another_root, 60);
  insertNode(another_root, 80);

  if (compare_trees(root, another_root))
  {
    printf("The trees are identical.\n");
  }
  else
  {
    printf("The trees are not identical.\n");
  }

  // Free the trees and arrays
  free_tree(root);
  free_tree(another_root);
  free_array_list(arr);

  return 0;
}
