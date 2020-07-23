#include "binary_trees.h"

/**
 * add_new_node - add a new node to de AVL tree.
 *
 * @parent: root of the tree.
 * @value: value of the new node.
 *
 * Return: returns the new node.
 */

avl_t *add_new_node (avl_t *parent, int value)
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
	avl_t *parent_tree_to_balance = NULL;
	avl_t *new_balanced_tree = NULL;
	int direction;

	if (tree == NULL || *tree == NULL || node == NULL || *is_balanced == 1)
		return;

	balance = binary_tree_balance((const binary_tree_t *) node);
	/*printf("\n\nnode-> %d, balance-> %d\n", node->n, balance);
	if (node->left != NULL)
		printf("    izq = %d\n", (node->left)->n);
	if (node->right != NULL)
		printf("    der = %d\n", (node->right)->n);*/

	if (balance > 1 || balance < -1)
	{
		if (node == *tree)
			*tree = binary_tree_rotate_right((binary_tree_t *)node);
		else
		{
			/* save data before balancing since node */
			parent_tree_to_balance = node->parent;
			if (parent_tree_to_balance->left != NULL &&
				parent_tree_to_balance->left == node)
				direction = -1;
			else if (parent_tree_to_balance->right != NULL &&
					 parent_tree_to_balance->right == node)
				direction = 1;

			/* balancing */
			if (balance > 1)
				new_balanced_tree = binary_tree_rotate_right((binary_tree_t *)node);
			else if (balance < -1)
				new_balanced_tree = binary_tree_rotate_left((binary_tree_t *)node);

			/* connecting balanced tree */
			new_balanced_tree->parent = parent_tree_to_balance;
			if (direction == -1)
				parent_tree_to_balance->left = new_balanced_tree;
			if (direction == 1)
				parent_tree_to_balance->right = new_balanced_tree;
		}
		*is_balanced = 1;
	}

	if (*is_balanced == 0)
		balance_sub_tree(tree, node->left, is_balanced);
	if (*is_balanced == 0)
		balance_sub_tree(tree, node->right, is_balanced);
}

/**
 * avl_insert - function that inserts a value in an AVL Tree.
 *
 * @tree: double pointer to the root node of the AVL tree for inserting the value.
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

	balance_sub_tree(tree, *tree, &balanced);

	return (new_node);
}
