#include "binary_trees.h"

/**
 * binary_tree_height - calculate the height of binary trees
 * @tree: the tree to be traversed
 * Return: the size of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t leftsize, rightsize;

	if (tree == NULL)
		return (0);
	leftsize = binary_tree_height(tree->left);
	rightsize = binary_tree_height(tree->right);

	return (1 + (rightsize > leftsize ? rightsize : leftsize));
}
