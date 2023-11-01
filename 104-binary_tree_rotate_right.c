#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotates a binary tree to the right
 * @tree: tree to work on
 * Return: pointer to new root
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	bt_t *temp;

	if (!tree || !tree->left)
		return (NULL);
	temp = tree->left;

	if (temp->right)
		temp->right->parent = tree;

	tree->left = temp->right;
	temp->parent = tree->parent;
	temp->right = tree;
	tree->parent = temp;

	return (temp);
}
