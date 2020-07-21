#include "binary_trees.h"

/**
 * height_tree - function for obtain the height of a binary tree.
 *
 * @tree: pointer to the root node of the tree to measure the height.
 * @ptr_height: pointer to height variable.
 * @value: height of current branch.
 */

void height_tree(const binary_tree_t *tree, int *ptr_height, int value)
{
	if (*ptr_height < value)
		*ptr_height = value;

	if (tree->left != NULL)
		height_tree(tree->left, ptr_height, value + 1);

	if (tree->right != NULL)
		height_tree(tree->right, ptr_height, value + 1);
}

/**
 * size_count - function for obtain the size of a binary tree.
 *
 * @tree: pointer to the root node of the tree to measure the size.
 * @ptr_size: pointer to size variable.
 */

void size_count(const binary_tree_t *tree, int *ptr_size)
{
	*ptr_size += 1;

	if (tree->left != NULL)
		size_count(tree->left, ptr_size);

	if (tree->right != NULL)
		size_count(tree->right, ptr_size);
}

/**
 * _pow - function to calculate base ** exp
 * @base: base
 * @exp: exp
 * Return: base ** exp
 */

int _pow(int base, int exp)
{
	int result = 1;
	int i = 0;

	for (i = 0; i < exp; i++)
		result *= base;

	return (result);
}

/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if the tree is perfect.
 * If tree is NULL, return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height = 0;
	int size = 0;
	int temporal = 0;

	if (tree == NULL)
		return (0);

	height_tree(tree, &height, 0);
	size_count(tree, &size);

	temporal = _pow(2, height + 1) - 1;
	if (temporal == size)
		return (1);
	else
		return (0);
}
