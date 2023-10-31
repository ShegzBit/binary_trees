#include "binary_trees.h"

/**
 * binary_tree_size - calculates the how many nodes a binary tree
 * have
 * @tree: tree to determine size for
 * Return: returns the size
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	int size = 0, left = 0, right = 0;

	if (tree == NULL)
		return (0);
	left = binary_tree_size(tree->left);
	right = binary_tree_size(tree->right);

	size = left + right + 1;
	return (size);
}
