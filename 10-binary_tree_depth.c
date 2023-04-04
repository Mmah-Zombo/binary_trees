#include "binary_trees.h"

/**
 * binary_tree_depth - calculates the depth of a binary tree
 * @tree:  pointer to the root node of the tree
 * Return: the depth of the tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t T_depth = 0;

	if (tree == NULL || (tree->parent == NULL))
		return (0);

	T_depth = binary_tree_depth(tree->parent);

	return (T_depth + 1);
}
