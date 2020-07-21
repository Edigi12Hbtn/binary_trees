#include "binary_trees.h"

/**
 * parent_nodes_count - function for obtain the number of parent nodes.
 *
 * @tree: pointer to the root node of the tree to
 * measure the parent nodes number.
 * @ptr_parent_nodes: pointer to parent_nodes variable.
 */

void parent_nodes_count(const binary_tree_t *tree, size_t *ptr_parent_nodes)
{

	if (tree->left != NULL || tree->right != NULL)
		*ptr_parent_nodes += 1;

	if (tree->left != NULL)
		parent_nodes_count(tree->left, ptr_parent_nodes);

	if (tree->right != NULL)
		parent_nodes_count(tree->right, ptr_parent_nodes);
}

/**
 * binary_tree_parent_nodes - function that measures
 * the number of parent nodes.
 *
 * @tree: pointer to the root node of the tree to measure the parent_nodes.
 *
 * Return: returns the number of parent nodes from a binary tree.
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t parent_nodes = 0;

	if (tree == NULL)
		return (0);

	parent_nodes_count(tree, &parent_nodes);

	return (parent_nodes);
}
