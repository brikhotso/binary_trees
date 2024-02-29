#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t **queue, *current;
	int front = 0, rear = 0, non_full_node_seen = 0;

	if (tree == NULL)
		return (0);

	queue = malloc(sizeof(binary_tree_t *) * 1024);
	if (queue == NULL)
		return (0);

	queue[rear++] = (binary_tree_t *)tree;
	while (front < rear)
	{
		current = queue[front++];
		if (non_full_node_seen && (current->left || current->right))
		{
			free(queue);
			return (0);
		}
		if (current->left == NULL)
			non_full_node_seen = 1;
		else if (non_full_node_seen)
		{
			free(queue);
			return (0);
		}
		if (current->left != NULL)
			queue[rear++] = current->left;
		if (current->right == NULL)
			non_full_node_seen = 1;
		else if (non_full_node_seen)
		{
			free(queue);
			return (0);
		}
		if (current->right != NULL)
			queue[rear++] = current->right;
	}
	free(queue);
	return (1);
}
