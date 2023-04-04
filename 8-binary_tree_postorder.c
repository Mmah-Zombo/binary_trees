#include "binary_trees.h"

/**
 * binary_tree_postorder - traverse a binary tree in post order
 * @tree: pointer to the root of the tree
 * @func: pointer to the funtion that process each node's value
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
