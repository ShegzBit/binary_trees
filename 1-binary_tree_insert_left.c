#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts in the left of a node and
 * replaces node if any in the position
 * @parent: parent to insert node into
 * @value: value of new node
 * Return: NULL on failure | pointer to new node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
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
	if (parent->left == NULL)
		parent->left = child;
	/*else insert parent left in node left insert node*/
	else
	{
		child->left = parent->left;
		parent->left->parent = child;
		parent->left = child;
	}
	/*return node*/
	return (child);
}
