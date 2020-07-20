#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 * Return: a pointer to the new node, or NULL on failure
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);
	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	if (parent == NULL)
		return (node);

	if (value == parent->n)
	{
		free(node);
		return (NULL);
	}
	if (value < parent->n)
	{
		if (parent->left)
		{
			free(node);
			return (NULL);
		}
		parent->left = node;
	}
	else
	{
		if (parent->right)
		{
			free(node);
			return (NULL);
		}
		parent->right = node;
	}

	return (node);
}
