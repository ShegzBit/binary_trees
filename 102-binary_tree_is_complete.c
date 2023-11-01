#include "binary_trees.h"
#define HEIGHT binary_tree_height
#define DEPTH binary_tree_depth

/**
 * is_left - checks if a node is the left child of its parent
 * @tree: node to check
 * Return: -1 on tree is root or NULL|1 on left | 0 not left
 */
int is_left(const binary_tree_t *tree)
{
	if (!tree || !tree->parent)
		return (-1);
	if (tree->parent->left == tree)
		return (1);
	return (0);
}

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

/**
 * binary_tree_depth - finds how deep below the root a node is
 * @tree: node to determine root
 * Return: depth of node tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL || tree->parent == NULL)
		return (0);
	return (binary_tree_depth(tree->parent) + 1);
}

/**
 * binary_tree_is_complete - checks if tree is complete
 * @tree: tree to check
 * Return: 0 not complete | 1 is complete
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t height = 0;

	if (!tree)
		return (0);

	height = HEIGHT(tree);
	return (complete_helper(tree, height));
}

/**
 * complete_helper - helps is complete method
 * @tree: tree
 * @height: height
 * Return: is complete or not
 */
int complete_helper(const binary_tree_t *tree, size_t height)
{
	/*int l = 0, r = 0;*/

	if (!tree)
		return (0);
	if ((height - 1) == DEPTH(tree))
	{
		if (tree->left && !tree->right)
			return (1);
		if (!tree->left && !tree->right)
			return (is_left(tree));
	}
	if (height == DEPTH(tree))
	{
		if (!tree->left && !tree->right)
			return (1);
	}
	return (0);
}
