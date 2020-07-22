#include "binary_trees.h"

/**
 * binary_tree_rotate_left - function that performs a
 * left-rotation on a binary tree
 *
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root = NULL;
	binary_tree_t *old_root = tree;

	if (tree == NULL)
		return (NULL);

	if (tree->right == NULL)
		return (NULL);

	new_root = tree->right;

	/* new right child for old root */
	old_root->right = new_root->left;
	if (old_root->right)
		old_root->right->parent = old_root;

	new_root->left = old_root;
	new_root->parent = NULL;
	old_root->parent = new_root;

	return (new_root);
}
