#include "binary_trees.h"

/**
 * is_valid_bst - Helper function to recursively check if a binary tree
 *                is a valid Binary Search Tree
 * @tree: A pointer to the root node of the tree to check
 * @prev: A pointer to the previous value encountered during traversal
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int is_valid_bst(const binary_tree_t *tree, int *prev)
{
	if (tree == NULL)
		return (1);

	if (!is_valid_bst(tree->left, prev))
		return (0);

	if (*prev != -1 && tree->n <= *prev)
		return (0);
	*prev = tree->n;

	return (is_valid_bst(tree->right, prev));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if tree is a valid BST, and 0 otherwise.
 *         If tree is NULL, return 0.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int prev = -1;

	if (tree == NULL)
		return (0);

	return (is_valid_bst(tree, &prev));
}
