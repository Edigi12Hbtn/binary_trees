#include "binary_trees.h"

/**
 * binary_tree_insert_right - function that inserts a node
 * as the right-child of another node.
 *
 * @parent: pointer to parent node.
 * @value: value to insert in child node.
 *
 * Return: pointer to new child node or NULL if it fails.
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;
	binary_tree_t *current = NULL;

	if (parent == NULL)
		return (NULL);

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);
	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	if (parent->right != NULL)
	{
		current = parent->right;
		current->parent = node;
		node->right = current;
	}

	parent->right = node;

	return (node);
}
