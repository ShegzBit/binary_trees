#include "binary_trees.h"

/**
 * bst_insert - inserts in a bst
 * @tree: pointer to root of tree
 * @value: value to insert
 * Return: pointer to new node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node;

	(void)tree;
	node = malloc(sizeof(bst_t));
	node->n = value;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	return (node);
}
