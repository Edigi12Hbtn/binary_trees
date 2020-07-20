#include "binary_trees.h"

/**
 * height_count - function for obtain the height of a binary tree.
 *
 * @tree: pointer to the root node of the tree to measure the height.
 * @ptr_height: pointer to height variable.
 * @value: height of current branch.
 */

void height_count(const binary_tree_t *tree, size_t *ptr_height, size_t value)
{
	if (*ptr_height < value)
		*ptr_height = value;

	if (tree->left != NULL)
		height_count(tree->left, ptr_height, value + 1);

	if (tree->right != NULL)
		height_count(tree->right, ptr_height, value + 1);
}

/**
 * binary_tree_height - function that measures the height of a binary tree.
 *
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: returns the height of a binary tree.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0;

	if (tree == NULL)
		return (0);

	height_count(tree, &height, 0);

	return (height);
}
