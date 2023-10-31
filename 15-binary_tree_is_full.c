#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * if a binary has only 0 or two nodes
 * @tree: tree to operate on
 * Return: 0 not full | 1 is full
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int l = 0, r = 0;

	if (tree == NULL)
		return (0);
	l = binary_tree_is_full(tree->left);
	r = binary_tree_is_full(tree->right);
	if (tree->left && tree->right)
		return (l & r);
	if (!tree->left && !tree->right)
		return (1);
	return (0);
}
