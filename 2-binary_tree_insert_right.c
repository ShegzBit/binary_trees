#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts in the right of a node and
 * replaces node if any in the position
 * @parent: parent to insert node into
 * @value: value of new node
 * Return: NULL on failure | pointer to new node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	/*create node*/
	bt_t *child;

	if (parent == NULL)
		return (NULL);
	child = binary_tree_node(parent, value);
	/*check for alloc fail*/
	if (child == NULL)
		return (NULL);
	/*check if parent left is occupied and insert if NOT*/
	if (parent->right == NULL)
		parent->right = child;
	/*else insert parent left in node left insert node*/
	else
	{
		child->right = parent->right;
		parent->right->parent = child;
		parent->right = child;
	}
	/*return node*/
	return (child);
}
