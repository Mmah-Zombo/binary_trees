#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: the tree to be measured
 *
 * Return: the balance factor or 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int ln, rn;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	ln = tree_height(tree->left);
	rn = tree_height(tree->right);

	return (ln - rn);
}

/**
 * tree_height - height of binary tree
 * @tree: pointer to the root node of the tree
 * Return: height
 */

size_t tree_height(const binary_tree_t *tree)
{
	int height_left, height_right;

	if (tree == NULL)
		return (0);
	height_left = tree_height(tree->left) + 1;
	height_right = tree_height(tree->right) + 1;

	if (height_left > height_right)
		return (height_left);
	else
		return (height_right);
}
