#include "binary_trees.h"
#define MAX_SIZE 256

/**
 * binary_tree_is_complete - checks if tree is complete
 * @tree: tree to check
 * Return: 0 not complete | 1 is complete
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	const bt_t *queue[MAX_SIZE], *temp;
	int front = 0, back = 0;
	int is_flag = 0;

	if (!tree)
		return (0);
	if (queue == NULL)
		return (0);
	queue[back++] = tree;
	while (front < back)
	{
		temp = queue[front++];
		if (temp)
		{
			if (is_flag)
				return (0);
			queue[back++] = temp->left;
			queue[back++] = temp->right;
		}
		else
			is_flag = 1;
	}
	return (1);
}
