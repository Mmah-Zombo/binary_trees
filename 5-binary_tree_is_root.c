#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if a node is the root
 * @node: pointer to the node to be checked
 *
 * Return: 1 if it is a root or 0 if it's not
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
	{
		return (0);
	}

	if (node->parent == NULL)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}