#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (!tree)
		return (0);

	left_height = binary_tree_height2(tree->left);
	right_height = binary_tree_height2(tree->right);

	if (left_height == right_height)
	{
		if (binary_tree_is_perfect(tree->right) &&
			binary_tree_is_complete(tree->left))
			return (1);
	}
	else if (left_height == right_height + 1)
	{
		if (binary_tree_is_complete(tree->right) &&
			binary_tree_is_perfect(tree->left))
			return (1);
	}

	return (0);
}

/**
 * binary_tree_height2 - Calculates the height of a binary tree.
 * @tree: A pointer to the root node of the tree to calculate the height.
 *
 * Return: The height of the tree.
 */
int binary_tree_height2(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (!tree)
		return (0);

	left_height = binary_tree_height2(tree->left);
	right_height = binary_tree_height2(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (!tree)
		return (1);

	left_height = binary_tree_height2(tree->left);
	right_height = binary_tree_height2(tree->right);

	return (left_height == right_height && binary_tree_is_perfect(tree->left)
		&& binary_tree_is_perfect(tree->right));
}
