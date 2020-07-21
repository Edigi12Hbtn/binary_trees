#include "binary_trees.h"

/**
 * height - function for obtain the height of a binary tree.
 *
 * @tree: pointer to the root node of the tree to measure the height.
 * @ptr_height: pointer to height variable.
 * @value: height of current branch.
 */

void height(const binary_tree_t *tree, int *ptr_height, int value)
{
	if (*ptr_height < value)
		*ptr_height = value;

	if (tree->left != NULL)
		height(tree->left, ptr_height, value + 1);

	if (tree->right != NULL)
		height(tree->right, ptr_height, value + 1);
}

/**
 * binary_tree_balance - function that measures the
 * balance factor of a binary tree
 *
 * @tree: pointer to the root node of the tree to
 * measure the balance factor
 *
 * Return: the balance factor
 * (diference between the left and the right subtrees height)
 * If tree is NULL, return 0
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int height_left = 0;
	int height_right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
	{
		height_left++;
		height(tree->left, &height_left, 0);
	}
	if (tree->right)
	{
		height_right++;
		height(tree->right, &height_right, 0);
	}

	return (height_left - height_right);
}
