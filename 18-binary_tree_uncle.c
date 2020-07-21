#include "binary_trees.h"

/**
 * binary_tree_t - function that finds the uncle of a node.
 *
 * @node: pointer to the node to find the uncle.
 *
 * Return: returns a pointer to the uncle node.
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *grandpa = NULL;

	if (node == NULL)
		return (NULL);

	if (node->parent == NULL)
		return (NULL);

	if ((node->parent)->parent == NULL)
		return (NULL);

	grandpa = (node->parent)->parent;

	if (grandpa->left != node->parent)
		return (grandpa->left);
	else
		return (grandpa->right);
}
