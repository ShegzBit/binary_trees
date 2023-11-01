#include "binary_trees.h"

/**
 * bst_insert - inserts in a bst
 * @tree: pointer to root of tree
 * @value: value to insert
 * Return: pointer to new node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node, *temp = NULL, *temp2 = NULL;

	node = malloc(sizeof(bst_t));
	if (node == NULL)
		return (NULL);
	node->n = value;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	temp = *tree;

	while (temp)
	{
		temp2 = temp;
		if (node->n < temp->n)
			temp = temp->left;
		else
			temp = temp->right;
	}
	node->parent = temp2;
	if (!temp2)
		*tree = node;
	else if (node->n < temp2->n)
		temp2->left = node;
	else if (node->n > temp2->n)
		temp2->right = node;
	else
	{
		free(node);
		return (NULL);
	}

	return (node);
}
