#include "binary_trees.h"

/**
 * size_count - function for obtain the size of a binary tree.
 *
 * @tree: pointer to the root node of the tree to measure the size.
 * @ptr_size: pointer to size variable.
 */

void size_count(const binary_tree_t *tree, size_t *ptr_size)
{
	*ptr_size += 1;

	if (tree->left != NULL)
		size_count(tree->left, ptr_size);

	if (tree->right != NULL)
		size_count(tree->right, ptr_size);
}

/**
 * binary_tree_size - function that measures the size of a binary tree.
 *
 * @tree: pointer to the root node of the tree to measure the size.
 *
 * Return: returns the size of a binary tree.
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL)
		return (0);

	size_count(tree, &size);

	return (size);
}
