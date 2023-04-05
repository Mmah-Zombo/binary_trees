#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node, or NULL if none found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
					const binary_tree_t *second)
{
	size_t depth_first, depth_second;

	if (first == NULL || second == NULL)
		return (NULL);

	/* Get depth of each node */
	depth_first = binary_tree_depth(first);
	depth_second = binary_tree_depth(second);

	/* Move deeper node up to the same level as the other node */
	while (depth_first > depth_second)
	{
		first = first->parent;
		depth_first--;
	}
	while (depth_second > depth_first)
	{
		second = second->parent;
		depth_second--;
	}

	/* Move both nodes up until they meet at the same ancestor */
	while (first != second)
	{
		first = first->parent;
		second = second->parent;
	}

	return ((binary_tree_t *) first);
}
