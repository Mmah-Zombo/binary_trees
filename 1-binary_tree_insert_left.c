#include "binary_trees"

/**
 * binary_tree_insert_left - function that creates a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 * Return: pointer to the new node, or NULL on failure
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value) {
    binary_tree_insert_t *new_node;
    
    if (parent == NULL) {
        return (NULL);
    }

    new_node = binary_tree_node(parent, value);

    if (new_node == NULL) {
        return (NULL);
    }

    if (parent->left == NULL) {
        parent->left = new_node;
    }
    else {
        new_node->left = parent->left;
        parent->left->parent = new_node;
        parent->left = new_node;
    }

    return (new_node);

}