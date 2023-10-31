#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: parent of new node being created
 * @value: value of current node
 * Return: NULL on failure | pointer to new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	/*create a pointer and allocate*/
	bt_t *node;

	node = malloc(sizeof(bt_t));
	/*check for alloc failure*/
	if (node == NULL)
		return (NULL);
	/*Set pointers to NULL and n to value*/
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	node->n = value;
	return (node);
}
