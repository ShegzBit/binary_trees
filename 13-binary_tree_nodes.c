#include "binary_trees.h"

/**
 * binary_tree_nodes - counts how many nodes a tree has
 * @tree: tree to count leave on
 * Return: number of leaves on a tree
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (tree == NULL)
		return (0);
	left = binary_tree_nodes(tree->left);
	right = binary_tree_nodes(tree->right);

	if (tree->left || tree->right)
		return (left + right + 1);
	return (left + right);
}
