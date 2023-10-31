#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: tree to check
 * Return: 1 is leave | 0 not leave
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	/*check for parent is not null in case of check fail*/
	if (node == NULL)
		return (0);
	if (node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}
