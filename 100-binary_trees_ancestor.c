#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 * Return: A pointer to the lowest common ancestor node,
 *         or NULL if no common ancestor was found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *node1_parent, *node2_parent;

	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);


	node1_parent = first->parent, node2_parent = second->parent;
	if (first == node2_parent || !node1_parent || (!node1_parent->parent
						       && node2_parent))
		return (binary_trees_ancestor(first, node2_parent));
	else if (node1_parent == second || !node2_parent ||
		 (!node2_parent->parent && node1_parent))
		return (binary_trees_ancestor(node1_parent, second));

	return (binary_trees_ancestor(node1_parent, node2_parent));
}
