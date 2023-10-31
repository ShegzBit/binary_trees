#include "binary_trees.h"
#define MAX_SIZE 256

/**
 * binary_tree_levelorder - applies func on each node in a tree
 * on a level order
 * @tree: tree starting pointer
 * @func: func to call on each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const bt_t **queue;
	const bt_t *temp;
	int done = 0, remain = 0;

	if (!tree || !func)
		return;

	queue = malloc(sizeof(*queue) * MAX_SIZE);
	queue[remain++] = tree;

	while (done < remain)
	{
		temp = queue[done++];
		func(temp->n);
		if (temp->left)
			queue[remain++] = temp->left;
		if (temp->right)
			queue[remain++] = temp->right;
	}
	free(queue);
}
