#include "binary_trees.h"

/**
 * binary_tree_height - calculates the height of a binary tree
 * @tree: root of tree
 * Return: height of tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int left_path = 0, right_path = 0;

	if (tree == NULL)
		return (0);

	left_path = binary_tree_height(tree->left);
	right_path = binary_tree_height(tree->right);

	if (left_path >= right_path)
		return (left_path + 1);
	return (right_path + 1);
}

/**
 * binary_tree_balance - checks the balance factor of a tree
 * difference between the left subtree and the right subtree
 * height
 * @tree: tree to calculate for
 * Return: the balance factore of node tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (left_height - right_height);
}
