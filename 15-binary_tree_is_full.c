#include "binary_trees.h"

/**
 * binary_tree_full - goes through a binary tree using pre-order traversal
 * and determines if the tree is full.
 * @tree: Where tree is a pointer to the root node of the tree to traverse
 * @full: it says if the tree is a full binary tree.
 */

void binary_tree_full(const binary_tree_t *tree, int *full)
{
	if (tree == NULL)
		return;

	if (tree->left != NULL && tree->right == NULL)
	{
		*full = 0;
		return;
	}
	else if (tree->left == NULL && tree->right != NULL)
	{
		*full = 0;
		return;
	}

	if (tree->left)
		binary_tree_full(tree->left, full);
	if (tree->right)
		binary_tree_full(tree->right, full);
}

/**
 * binary_tree_is_full - function that checks if a binary tree is full.
 *
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is full, else 0.
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int full = 1;

	if (tree == NULL)
		return (0);

	binary_tree_full(tree, &full);

	return (full);
}
