#include "binary_trees.h"

/**
 * heap_insert - heap insert
 * @root: root pointer
 * @value: balue to insert into heap
 * Return: pointer to node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node;

	(void)root;
	if (root == NULL)
		return (NULL);
	node = malloc(sizeof(heap_t));
	node->parent = NULL;
	node->right = NULL;
	node->left = NULL;
	node->n = value;

	return (node);
}
