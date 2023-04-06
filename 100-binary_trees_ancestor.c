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

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 *
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node, or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *ptr1, *ptr2;
	size_t depth1, depth2;

	if (first == NULL || second == NULL)
		return (NULL);

	ptr1 = first;
	ptr2 = second;
	depth1 = binary_tree_depth(ptr1);
	depth2 = binary_tree_depth(ptr2);

	while (depth1 > depth2)
	{
		ptr1 = ptr1->parent;
		depth1--;
	}

	while (depth2 > depth1)
	{
		ptr2 = ptr2->parent;
		depth2--;
	}

	while (ptr1 != NULL && ptr2 != NULL)
	{
		if (ptr1 == ptr2)
			return ((binary_tree_t *) ptr1);

		ptr1 = ptr1->parent;
		ptr2 = ptr2->parent;
	}

	return (NULL);
}
