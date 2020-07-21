#include "binary_trees.h"

/**
 * launch_test - function that finds the
 * lowest common ancestor of two nodes.
 *
 * @first: first node.
 * @second: second node.
 *
 * Return: the ancestor node..
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
					const binary_tree_t *second)
{
	const binary_tree_t *ancestor_1 = first;
	const binary_tree_t *ancestor_2 = second;

	if (first == NULL || second == NULL)
		return (NULL);

	while (ancestor_1 != NULL)
	{
		ancestor_2 = second;
		while (ancestor_2 != NULL)
		{
			if (ancestor_1 == ancestor_2)
				return ((binary_tree_t *) ancestor_1);
			ancestor_2 = ancestor_2->parent;
		}
		ancestor_1 = ancestor_1->parent;
	}

	return (NULL);
}
