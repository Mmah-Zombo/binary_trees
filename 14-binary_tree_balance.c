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

	if (tree == NULL)
		return (0);

	ln = binary_tree_balance(tree->left);
	rn = binary_tree_balance(tree->right);

	ln++;
	rn++;

	return (ln > rn? ln - rn : rn - ln);
}
