#include "binary_trees.h"

/**
 * height_bt - checks the height of a binary tree
 * @tree: tree to work on
 * Return: height of tree
 */
int height_bt(const binary_tree_t *tree)
{
	int l = 0, r = 0;

	if (tree == NULL)
		return (-1);
	l = height_bt(tree->left);
	r = height_bt(tree->right);
	if (l >= r)
		return (l + 1);
	return (r + 1);
}

/**
 * size_bt - calculates the how many nodes a binary tree
 * have
 * @tree: tree to determine size for
 * Return: returns the size
 */
size_t size_bt(const binary_tree_t *tree)
{
	int size = 0, left = 0, right = 0;

	if (tree == NULL)
		return (0);
	left = size_bt(tree->left);
	right = size_bt(tree->right);

	size = left + right + 1;
	return (size);
}

/**
 * binary_tree_is_perfect - checks if a given tree or subtree
 * is perfect
 * has full number of childs for every node it in it
 * @tree: tree to work on
 * Return: 1 is perfect | 0 not perfect
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int h_equal = 0, n_equal = 0;
	/*check if a tree is null*/
	if (tree == NULL)
		return (0);
	binary_tree_is_perfect(tree->left);
	binary_tree_is_perfect(tree->right);
	/*if it has only one child*/
	if ((tree->left && !tree->right) || (!tree->left && tree->right))
		return (0);
	/*if it has both child confirm they are of the same height*/
	if (tree->left && tree->right)
	{
		h_equal = height_bt(tree->left) == height_bt(tree->right);
		n_equal = size_bt(tree->left) == size_bt(tree->right);
		return (h_equal & n_equal);
	}
	return (0);
}
