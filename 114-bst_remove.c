#include "binary_trees.h"

/**
 * bst_search - function that searches for a value in
 * a Binary Search Tree
 *
 * @tree: pointer to the root node of the BST to search
 * @value: is the value to search in the tree
 *
 * Return: a pointer to the node containing a value equals to value
 * If tree is NULL or if nothing is found, return NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	while (tree)
	{
		if (value == tree->n)
			return ((bst_t *) tree);
		else if (value < tree->n)
			tree = tree->left;
		else if (value > tree->n)
			tree = tree->right;
	}

	return (NULL);
}

/**
 * bst_remove - function that removes a node from a Binary Search Tree.
 *
 * @root: root of binary search tree.
 * @value: value in node to remove.
 *
 * Return: a pointer to the new root node of
 * the tree after removing the desired value.
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *new_root = NULL, *node_to_delete = NULL, *left_child = NULL;
	bst_t *right_child = NULL, *parent = NULL;

	if (root == NULL)
		return (NULL);

	node_to_delete = bst_search((const bst_t *) root, value);
	if (node_to_delete == NULL)
		return (NULL);

	parent = node_to_delete->parent;/* NULL*/
	left_child = node_to_delete->left; /*47*/
	right_child = node_to_delete->right;/* 87*/
	new_root = right_child; /*84*/
	free(node_to_delete);


	while (right_child != NULL && new_root->left != NULL)
			new_root = new_root->left;

	if (right_child == NULL)
	{
		if (left_child != NULL)
			left_child->parent = parent;
		if (parent != NULL && (parent->left == node_to_delete))
			parent->left = left_child;
		else if (parent != NULL && (parent->right == node_to_delete))
			parent->right = left_child;
		else
			root = left_child;
		return (root);
	}

	if (root == node_to_delete)
		root = new_root;

	if (new_root != right_child)
	{
		(new_root->parent)->left = new_root->right;
		if (new_root->right != NULL)
			(new_root->right)->parent = new_root->parent;

		new_root->right = right_child;
		if (right_child != NULL)
			right_child->parent = new_root;
	}

	new_root->left = left_child;
	if (left_child != NULL)
		left_child->parent = new_root;
		
	new_root->parent = parent;
	if (parent != NULL && (parent->left == node_to_delete))
		parent->left = new_root;
	else if (parent != NULL && (parent->right == node_to_delete))
		parent->right = new_root;

	return (root);
}
/**
 * 1. delete node and free.
 * 2. find the most recursive left grandchild of our right tree.
 * 3. become that node the new sub-root.
 * 4. connect the right sub-tree there and then insert on its left the remain node (right of new sub-root).
 */
