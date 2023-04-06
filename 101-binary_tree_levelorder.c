#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal
 * @tree: A pointer to the root node of the tree to traverse
 * @func: A pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	queue_t *queue = NULL;

	enqueue(&queue, (binary_tree_t *)tree);

	while (queue != NULL)
	{
		binary_tree_t *node = dequeue(&queue);
		func(node->n);

		if (node->left != NULL)
			enqueue(&queue, node->left);

		if (node->right != NULL)
			enqueue(&queue, node->right);
	}
}
