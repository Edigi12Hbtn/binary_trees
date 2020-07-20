#include "binary_trees.h"

/**
 * binary_tree_t - function that inserts a node
 * as the left-child of another node.
 *
 * @parent: pointer to parent node.
 * @value: value to insert in child node.
 *
 * Return: pointer to new child node or NULL if it fails.
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
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

	if (parent->left != NULL)
	{
		current = parent->left;
		current->parent = node;
		node->left = current;
	}

	parent->left = node;

	return (node);
}
