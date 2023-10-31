#include "binary_trees.h"

/**
 * binary_tree_sibling - returns the sibling of a node
 * @node: node of whose sibling to find
 * Return: pointer to node sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	/*check for null nodes*/
	if (!node || !node->parent)
		return (NULL);
	/*check what child it is and return other child*/
	if (node->parent->left == node)
		return (node->parent->right);
	if (node->parent->right == node)
		return (node->parent->left);
	return (NULL);
}
