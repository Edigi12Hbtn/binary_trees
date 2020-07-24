#include "binary_trees.h"

/**
 * height_count - function for obtain the height of a binary tree.
 *
 * @tree: pointer to the root node of the tree to measure the height.
 * @ptr_height: pointer to height variable.
 * @value: height of current branch.
 */

void height_count(const binary_tree_t *tree, int *ptr_height, int value)
{
	if (*ptr_height < value)
		*ptr_height = value;

	if (tree->left != NULL)
		height_count(tree->left, ptr_height, value + 1);

	if (tree->right != NULL)
		height_count(tree->right, ptr_height, value + 1);
}

/**
 * print_level - function for print the level of a tree
 *
 * @tree: pointer to the root node of the tree.
 * @level: level to be printed.
 * @func: function to print a node.
 */

void print_level(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (tree == NULL)
		return;

	if (level == 0)
	{
		func(tree->n);
		return;
	}

	if (tree->left != NULL)
		print_level(tree->left, level - 1, func);

	if (tree->right != NULL)
		print_level(tree->right, level - 1, func);
}

/**
 * binary_tree_levelorder - function that goes through
 * a binary tree using level-order traversal
 *
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function.
 * If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height = 0;
	int i = 0;

	if (tree == NULL || func == NULL)
		return;

	height_count(tree, &height, 1);

	for (i = 0; i <= height; i++)
		print_level(tree, i, func);
}
