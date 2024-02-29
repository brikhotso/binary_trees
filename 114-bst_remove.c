#include "binary_trees.h"

/**
 * find_successor - Finds the in-order successor of a node
 * @node: A pointer to the node to find the successor of
 * Return: A pointer to the in-order successor node
 */
bst_t *find_successor(bst_t *node)
{
	node = node->right;
	while (node && node->left)
		node = node->left;
	return (node);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: A pointer to the root node of the tree where you will remove a node
 * @value: The value to remove in the tree
 * Return: A pointer to the new root node of the tree after removing value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *successor, *temp;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}

		successor = find_successor(root);
		root->n = successor->n;
		root->right = bst_remove(root->right, successor->n);
	}

	return (root);
}
