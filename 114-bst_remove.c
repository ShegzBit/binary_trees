#include "binary_trees.h"

/**
 * min - min
 * @root: root
 * Return: min
 */
bst_t *min(bst_t *root)
{
	while (root->right)
		root = root->right;
	return (x);
}

/**
 * successor - successor
 * @root: root
 * Return: successor
 */
bst_t *successor(bst_t *root)
{
	bst_t *temp = NULL;

	if (root->right)
		return (min(root->right));
	temp = root->parent;
	while (temp && root = temp->right)
	{
		root = temp;
		temp = temp->parent;
	}
	return (temp);
}

/**
 * shift_nodes - shifts node
 * @tree: tree
 * @node: node
 * @new: new
 */
void shift_nodes(bst_t **tree, bst_t **node, bst_t **new)
{
	bst_t *_node = *node, *_new = *new;

	if (!_node->parent)
		*tree = _new;
	else if (_node == _node->parent->left)
		_node->parent->left = _new;
	else
		_node->parent->right = _new;
	if (_new)
		_new->parent = _node->parent;
}

/**
 * bst_remove - removes node with a value
 * @root: root of tree
 * @value: value to remove
 * Return: removed node
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp
	return (NULL);
}
