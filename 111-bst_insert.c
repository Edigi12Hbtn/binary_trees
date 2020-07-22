#include "binary_trees.h"

/**
 * bst_insert - function that inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 *
 * Return: a pointer to the created node, or NULL on failure
 * If the address stored in tree is NULL, the created node must become the root node.
 * If the value is already present in the tree, it must be ignored
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node = NULL;
	bst_t *current = NULL;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	current = *tree;
	while (current)
	{
		if (value == current->n)
			return (NULL);

		if (value < current->n)
		{
			if (current->left == NULL)
			{
				node = binary_tree_node(current, value);
				current->left = node;
				return (node);
			}
			current = current->left;
		}
		else if (value > current->n)
		{
			if (current->right == NULL)
			{
				node = binary_tree_node(current, value);
				current->right = node;
				return (node);
			}
			current = current->right;
		}
	}

	return (NULL);
}
