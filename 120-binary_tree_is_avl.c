#include "binary_trees.h"

/**
 * check_node_right - check if the right branch of the tree is also a bst.
 *
 * @node: node of the tree.
 * @all_right: 1 if the branch is a bst otherwise -1.
 * @m: value in the root node.
 */

void check_node_right(binary_tree_t *node, int *all_right, int m)
{
	if (node == NULL || *all_right == -1)
		return;

	if (node->n <= m)
	{
		*all_right = -1;
		return;
	}

	if (node->left != NULL)
		check_node_right(node->left, all_right, m);

	if (node->right != NULL)
		check_node_right(node->right, all_right, m);
}

/**
 * check_node_left - check if the left branch of the tree is also a bst.
 *
 * @node: node of the tree.
 * @all_right: 1 if the branch is a bst otherwise -1.
 * @m: value in the root node.
 */

void check_node_left(binary_tree_t *node, int *all_right, int m)
{
	if (node == NULL || *all_right == -1)
		return;

	if (node->n >= m)
	{
		*all_right = -1;
		return;
	}

	if (node->left != NULL)
		check_node_left(node->left, all_right, m);

	if (node->right != NULL)
		check_node_left(node->right, all_right, m);
}

/**
 * check_if_bst - cheks if every node is a root of a bst.
 *
 * @current_node: current node to check.
 * @all_right: 1 if the branches are bst otherwise -1.
 */

void check_if_bst(binary_tree_t *current_node, int *all_right)
{
	if (current_node == NULL || *all_right == -1)
		return;

	check_node_right(current_node->right, all_right, current_node->n);
	if (*all_right != 1)
		return;

	check_node_left(current_node->left, all_right, current_node->n);
	if (*all_right != 1)
		return;
	if (current_node->left)
		check_if_bst(current_node->left, all_right);
	if (current_node->right)
		check_if_bst(current_node->right, all_right);
}

/**
 * binary_tree_is_bst - function that checks if a binary
 * tree is a valid Binary Search Tree.
 *
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if the binary tree is a bst otherwise 0.
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	int all_right = 1;

	if (tree == NULL)
		return (0);

	check_if_bst((binary_tree_t *)tree, &all_right);

	if (all_right != 1)
		return (0);

	return (1);
}

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
 * binary_tree_is_avl - function that checks if a binary tree is
 * a valid AVL Tree
 *
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 * f tree is NULL, return 0
 * Properties of an AVL Tree:
 * - An AVL Tree is a BST
 * - The difference between heights of left and right subtrees cannot be more than one
 * - The left and right subtree each must also be a binary search tree
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int balance;
	int height_left = 0;
	int height_right = 0;

	if (tree == NULL)
		return (0);

	/* same as binary_tree_balance */
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

	balance = height_left - height_right;
	if (balance > 1 || balance < -1)
		return (0);

	if (binary_tree_is_bst(tree) == 0)
		return (0);

	return (1);
}
