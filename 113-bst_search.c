#include "binary_trees.h"
#define LEFT tree->left
#define RIGHT tree->right

/**
 * bst_search - searches for value in tree
 * @tree: tree to lookthrough
 * @value: value to lookup
 * Return: node conataining value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	const bst_t *temp = NULL;

	for (; tree;)
	{
		temp = tree;
		if (value < tree->n)
			tree = LEFT;
		else if (value > tree->n)
			tree = RIGHT;
		else
			break;
	}

	if (tree)
		return ((bst_t *)temp);
	return (NULL);
}
