#include "binary_trees.h"
#include <stdlib.h>

typedef struct queue_s
{
	struct binary_tree_s *node;
	struct queue_s *next;
} queue_t;

/**
 * enqueue - Adds a node to the end of the queue
 * @queue: A pointer to the queue to add the node to
 * @node: A pointer to the node to add to the queue
 */
void enqueue(queue_t **queue, binary_tree_t *node)
{
	queue_t *new_node = malloc(sizeof(queue_t));

	if (new_node == NULL)
		return;

	new_node->node = node;
	new_node->next = NULL;

	if (*queue == NULL)
		*queue = new_node;
	else
	{
		queue_t *temp = *queue;

		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
}
/**
 * dequeue - Removes the first node from the queue
 * @queue: A pointer to the queue to remove the node from
 *
 * Return: A pointer to the removed node
 */
binary_tree_t *dequeue(queue_t **queue)
{
	if (*queue == NULL)
		return NULL;

	binary_tree_t *node = (*queue)->node;
	queue_t *temp = *queue;

	*queue = (*queue)->next;
	free(temp);

	return node;
}

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
