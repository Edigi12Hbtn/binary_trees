#include "binary_trees.h"

/**
 * array_to_bst - function that builds a Binary Search Tree from an array.
 *
 * @array: array to create the bst.
 * @size: size of the array.
 *
 * Return: the root of the new bst.
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i = 0;

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
		bst_insert(&tree, array[i]);

	return (tree);
}
