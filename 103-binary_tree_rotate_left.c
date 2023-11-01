#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotates a binary tree to the left
 * @tree: tree to work on
 * Return: pointer to new root
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	bt_t *temp;

	if (!tree || !tree->right)
		return (NULL);
	temp = tree->right;

	if (temp->left)
		temp->left->parent = tree;

	tree->right = temp->left;
	temp->parent = tree->parent;
	temp->left = tree;
	tree->parent = temp;

	return (temp);
}
