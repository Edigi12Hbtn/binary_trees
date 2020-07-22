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
 * save_information_find_new_root - store information of node to
 * be deleted and find the new node that is going to replace it (new_root).
 *
 * @parent: parent of node_to_delete.
 * @left_child: left child of node_to_delete.
 * @right_child: right child of node_to_delete.
 * @new_root: node that is going to replace the node_to_delete.
 * @node_to_delete: node that is going to be deleted.
 */

void save_information_find_new_root(bst_t **parent,
				bst_t **left_child,
				bst_t **right_child, bst_t **new_root,
				bst_t **node_to_delete)
{
	*parent = (*node_to_delete)->parent;
	*left_child = (*node_to_delete)->left;
	*right_child = (*node_to_delete)->right;
	*new_root = *right_child;
	free(*node_to_delete);

	while (*right_child != NULL && (*new_root)->left != NULL)
		*new_root = (*new_root)->left;
}

/**
 * case_right_child_null - function that manage the case where
 * right_child is NULL.
 *
 * @parent: parent of node_to_delete.
 * @left_child: left child of node_to_delete.
 * @right_child: right child of node_to_delete.
 * @node_to_delete: node that is going to be deleted.
 * @root: root of the hole tree.
 *
 * Return: 1 if the program has to finish returning the root,
 * 0 if not.
 */

int case_right_child_null(bst_t **parent,
			bst_t **left_child,
			bst_t **right_child,
			bst_t **node_to_delete,
			bst_t **root)
{

	if (*right_child == NULL)
	{
		if (*left_child != NULL)
			(*left_child)->parent = *parent;
		if (*parent != NULL && ((*parent)->left == *node_to_delete))
			(*parent)->left = *left_child;
		else if (*parent != NULL && ((*parent)->right == *node_to_delete))
			(*parent)->right = *left_child;
		else
			*root = *left_child;
		return (1);/*the program has to return (*root);*/
	}
		return (0);
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

	save_information_find_new_root(&parent, &left_child,
				&right_child, &new_root, &node_to_delete);

	if (case_right_child_null(&parent, &left_child, &right_child,
				&node_to_delete, &root))
		return (root);
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
