#include "binary_trees.h"

/**
 * binary_tree_rotate_right - function that performs a
 * right-rotation on a binary tree
 *
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root = NULL;
	binary_tree_t *old_root = tree;

	if (tree == NULL)
		return (NULL);

	if (tree->left == NULL)
		return (NULL);

	new_root = tree->left;

	/* new right child for old root */
	old_root->left = new_root->right;
	if (old_root->left)
		old_root->left->parent = old_root;

	new_root->right = old_root;
	new_root->parent = old_root->parent;
	old_root->parent = new_root;

	/* check side of the new rotated tree */
	if (new_root->parent != NULL)
	{
		if (new_root->parent->right == old_root)
			new_root->parent->right = new_root;
		else if (new_root->parent->left == old_root)
			new_root->parent->left = new_root;
	}

	return (new_root);
}
