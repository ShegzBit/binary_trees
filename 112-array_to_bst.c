#include "binary_trees.h"
#define INSERT bst_insert


/**
 * array_to_bst - builds a binary tree from an array
 * @array: array to build from
 * @size: of the array
 * Return: binary search tree
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i;

	if (!array)
		return (NULL);
	for (i = 0; i < size; i++)
		INSERT(&tree, array[i]);

	return (tree);
}
