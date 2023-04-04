#include "binary_trees.h"

/**
 * binary_tree_inorder - traverse a binary tree using inorder
 * @tree: pointer to the root nod of the tree
 * @fun: function to process the values of the node
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || free == NULL)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
