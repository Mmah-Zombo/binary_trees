#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 *
 * @tree: pointer to the root node of the tree to count the number of nodes
 *
 * Return: number of nodes with at least 1 child, or 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t rightN, leftN;

	if (tree == NULL || (tree->left == NULL && tree->left == NULL))
		return (0);

	rightN = binary_tree_nodes(tree->right);
	leftN = binary_tree_nodes(tree->left);

	return (rightN + leftN + 1);
}
