#include "binary_trees.h"

/**
 * leaf_count - function for obtain the leaves of a binary tree.
 *
 * @tree: pointer to the root node of the tree to count the leaves.
 * @ptr_total: pointer to leaf count variable.
 */

void leaf_count(const binary_tree_t *tree, size_t *ptr_total)
{
	if (tree->left == NULL && tree->right == NULL)
		*ptr_total += 1;

	if (tree->left != NULL)
		leaf_count(tree->left, ptr_total);

	if (tree->right != NULL)
		leaf_count(tree->right, ptr_total);
}

/**
 * binary_tree_leaves - function that counts the leaves in a binary tree
 * @tree: pointer to the root node of the
 * tree to count the number of leaves
 *
 * Return: number of leaves
 * If tree is NULL, the function must return 0
 * A NULL pointer is not a leaf
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t total = 0;

	if (tree == NULL)
		return (0);

	leaf_count(tree, &total);

	return (total);
}
