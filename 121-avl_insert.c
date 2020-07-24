#include "binary_trees.h"

/**
 * add_new_node - add a new node to de AVL tree.
 *
 * @parent: root of the tree.
 * @value: value of the new node.
 *
 * Return: returns the new node.
 */

avl_t *add_new_node(avl_t *parent, int value)
{
	while (parent != NULL)
	{
		if (parent->n == value)
			return (NULL);
		else if (parent->n > value)
		{
			if (parent->left != NULL)
				parent = parent->left;
			else
			{
				parent->left = binary_tree_node(parent, value);
				return (parent->left);
			}
		}
		else if (parent->n < value)
		{
			if (parent->right != NULL)
				parent = parent->right;
			else
			{
				parent->right = binary_tree_node(parent, value);
				return (parent->right);
			}
		}
	}

	return (NULL);
}

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
 * balance_when_height_is_more_than_2 - balance when grandson have childrens
 *
 * @tree: all tree
 * @node: pointer to the root node of the subtree to balance
 * @balance: to know in wich direction make rotations
 *
 */
void balance_when_height_is_more_than_2(avl_t **tree, avl_t *node, int balance)
{
	avl_t *aux = NULL;
	int balance_subtree = 0;

	if (balance > 1)
	{
		balance_subtree = binary_tree_balance((const binary_tree_t *)node->left);
		if (balance_subtree < 0)
			binary_tree_rotate_left((binary_tree_t *)node->left);
	}
	else if (balance < -1)
	{
		balance_subtree = binary_tree_balance((const binary_tree_t *)node->right);
		if (balance_subtree > 0)
			binary_tree_rotate_right((binary_tree_t *)node->right);
	}

	if (balance > 1)
		aux = binary_tree_rotate_right((binary_tree_t *)node);
	else if (balance < -1)
		aux = binary_tree_rotate_left((binary_tree_t *)node);

	if (node == *tree)
		*tree = aux;
}

/**
 * balance_sub_tree - look for a non balanced subtree and if is found
 * it is balanced.
 *
 * @tree: doble pointer to the root of the tree. Needed if the root is rotated.
 * @node: pass through all the nodes.
 * @is_balanced: 1 if the tree is balanced, 0 if not.
 */

void balance_sub_tree(avl_t **tree, avl_t *node, int *is_balanced)
{
	int balance = 0;
	size_t height = 0;
	avl_t *aux = NULL;

	if (tree == NULL || *tree == NULL || node == NULL || *is_balanced == 1)
		return;

	if (*is_balanced == 0)
		balance_sub_tree(tree, node->left, is_balanced);
	if (*is_balanced == 0)
		balance_sub_tree(tree, node->right, is_balanced);

	balance = binary_tree_balance((const binary_tree_t *)node);

	if (balance > 1 || balance < -1)
	{
		height_count(node, &height, 0);
		/* when the granson don't have childrens */
		if (height == 2)
		{
			/* if this is a zig zag, rotate the node->child */
			if (balance > 1 && node->left)
				binary_tree_rotate_left((binary_tree_t *)node->left);
			else if (balance < -1 && node->right)
				binary_tree_rotate_right((binary_tree_t *)node->right);

			if (balance > 1)
				aux = binary_tree_rotate_right((binary_tree_t *)node);
			else if (balance < -1)
				aux = binary_tree_rotate_left((binary_tree_t *)node);

			if (node == *tree)
				*tree = aux;
		}
		else
			balance_when_height_is_more_than_2(tree, node, balance);

		*is_balanced = 1;
	}
}

/**
 * avl_insert - function that inserts a value in an AVL Tree.
 *
 * @tree: double pointer to the root node of
 * the AVL tree for inserting the value.
 * @value: value to store in the node to be inserted.
 *
 * Return: a pointer to the created node, or NULL on failure.
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;
	int balanced = 0;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(*tree, value);
		return (*tree);
	}
	new_node = add_new_node(*tree, value);
	if (new_node == NULL)
		return (NULL);

	balance_sub_tree(tree, *tree, &balanced);

	return (new_node);
}
