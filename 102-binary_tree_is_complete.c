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
 * left_nodes - function for obtain the height of a binary tree.
 *
 * @tree: pointer to the root node of the tree to measure the height.
 * @ptr_height: pointer to height variable.
 * @value: height of current branch.
 */

void left_nodes(const binary_tree_t *tree, size_t height,
		size_t value, int *flag)
{

	if (*flag == -1)
		return;

	if (value == height - 1)
	{
		if (tree->left != NULL && *flag == 0)
		{
			*flag = -1;
			return;
		}
		if (tree->left == NULL && *flag == 1)
			*flag = 0;
		
		if (tree->right != NULL && *flag == 0)
		{
			*flag = -1;
			return;
		}
		if(tree->right == NULL && *flag == 1)
			*flag = 0;
		return;
	}

	if (tree->left != NULL)
		left_nodes(tree->left, height, value + 1, flag);

	if (tree->right != NULL)
		left_nodes(tree->right, height, value + 1, flag);
}

/**
 * binary_tree_is_complete - function that checks if
 * a binary tree is complete.
 *
 * @tree: tree is a pointer to the root
 * node of the tree to check.
 *
 * Return: 1 if the binary tree is complete 0 if not.
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size = 0, height = 0;
	size_t minimum_size = 0, max_size = 0;
	int nodes_at_left = 1;

	if (tree == NULL)
		return (0);

	size_count(tree, &size);
	height_count(tree, &height, 0);

	max_size = _pow(2, height + 1) - 1;
	minimum_size = _pow(2, height) - 1;

	if (minimum_size >= size || size > max_size)
		return (0);
	else if (size == max_size)
		return (1);

	left_nodes(tree, height, 0, &nodes_at_left);

	if (nodes_at_left == -1 || nodes_at_left == 1)
		return (0);

	return (1);
}
