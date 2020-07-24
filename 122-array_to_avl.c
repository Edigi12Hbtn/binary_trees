#include "binary_trees.h"

/**
 * array_to_avl - function that builds an AVL tree from an array
 *
 * @array: pointer to the first element of the array to be converted
 * @size: is the number of element in the array
 *
 * Return: a pointer to the root node of the
 * created AVL tree, or NULL on failure
 * If a value of the array is already present in the tree,
 * this value must be ignored
 */

avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t i = 0;

	if (array == NULL || size == 0)
		return (NULL);
	for (i = 0; i < size; i++)
		avl_insert(&tree, array[i]);
	return (tree);
}
