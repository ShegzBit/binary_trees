#include "binary_trees.h"

/**
 * binary_tree_height - calculates the height of a binary tree
 * @tree: root of tree
 * Return: height of tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int left_path = 0, right_path = 0, has_traversed = 0;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);
	else if (tree == NULL && has_traversed)
		return (-1);
	has_traversed = 1;
	left_path = binary_tree_height(tree->left);
	right_path = binary_tree_height(tree->right);

	if (left_path >= right_path)
		return (left_path + 1);
	return (right_path + 1);
}
