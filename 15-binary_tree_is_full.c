#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	/* An empty tree is full by definition */
	if (tree == NULL)
		return 1;

	/* If either child is missing, the tree is not full */
	if (tree->left == NULL && tree->right == NULL)
		return 1;
	if (tree->left == NULL || tree->right == NULL)
		return 0;

	/* Recursively check the left and right subtrees */
	return (binary_tree_is_full(tree->left) &&
			binary_tree_is_full(tree->right));
}
