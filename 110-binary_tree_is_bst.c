#include "binary_trees.h"
#include <limits.h>
#define RIGHT tree->right
#define LEFT tree->left
#define TN tree->n

/**
 * binary_tree_is_bst - checks if a tree is a bst
 * @tree: tree to works
 * Return: 1 on true | false
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (bst_helper(tree, INT_MIN, INT_MAX));
}

/**
 * bst_helper - helps binray tree in recursive call int limits
 * @tree: tree to work on
 * @min: minimum number
 * @max: maximum number
 * Return: 1 is bst | 0 not bst
 */
int bst_helper(const bst_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (min >= TN || max <= TN)
		return (0);
	return (bst_helper(LEFT, min, TN - 1) && bst_helper(RIGHT, TN + 1, max));
}
