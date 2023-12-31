#include "binary_trees.h"
#define N_LEFT (&((*node)->left))
#define N_RIGHT (&((*node)->right))
#define NODE (*node)
#define SEARCH bst_search
#define LEFT tree->left
#define RIGHT tree->right


/**
 * min - min
 * @root: root
 * Return: min
 */
bst_t *min(bst_t *root)
{
	while (root->right)
		root = root->right;
	return (root);
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
	while (temp && root == temp->right)
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
 * delete_node - deletes a node from a tree
 * @tree: tree from which to delete
 * @node: node to delete
 * Return: deleted node
 */
bst_t *delete_node(bst_t **tree, bst_t **node)
{
	bst_t *temp;

	if (*(N_LEFT))
	{
		shift_nodes(tree, node, N_RIGHT);
		free(*node);
		return (*N_RIGHT);
	}
	else if (*(N_RIGHT))
	{
		shift_nodes(tree, node, N_LEFT);
		free(*node);
		return (*N_LEFT);
	}
	else
	{
		temp = successor(NODE);
		if (temp->parent != NODE)
		{
			shift_nodes(tree, &temp, N_RIGHT);
			temp->right = *(N_RIGHT);
			if (temp->right)
				temp->right->parent = temp;
		}
		temp->left = *(N_LEFT);
		temp->left->parent = temp;
		shift_nodes(tree, node, &temp);
		free(*node);
	}

	return (temp);
}

/**
 * bst_remove - removes node with a value
 * @root: root of tree
 * @value: value to remove
 * Return: removed node
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node = NULL;
	bst_t *tree = root;
	bst_t *temp = NULL;

	for (; tree;)
	{
		temp = tree;
		if (value < tree->n)
			tree = tree->left;
		else if (value > tree->n)
			tree = tree->right;
		else
			break;
	}
	node = (tree ? (bst_t *)temp : NULL);
	if (!node)
		return (NULL);
	delete_node(&root, &node);
	return (root);
}
