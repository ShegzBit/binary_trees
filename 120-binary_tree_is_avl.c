#include "binary_trees.h"
#include <limits.h>

#define LEFT tree->left
#define RIGHT tree->right
#define TN tree->n
#define HEIGHT binary_tree_height
#define HELPER is_avl_helper


size_t binary_tree_height(const binary_tree_t *tree);

/**
 * is_avl_helper - helps bst is avl in recursive call with
 * min and max value for each node
 * @tree: bst root
 * @min: min value
 * @max: max value
 * Return: 1 is avl | 0 not avl
 */
int is_avl_helper(const binary_tree_t *tree, int min, int max)
{
	int b_factor = 0;

	if (!tree)
		return (1);
	if (min > TN || max < TN)
		return (0);
	if (min < TN && max > TN)
	{
		b_factor = HEIGHT(LEFT) - HEIGHT(RIGHT);
		/*printf("b_factor -> %d\n", b_factor);*/
		if (b_factor >= -1 && b_factor <= 1)
			return (HELPER(LEFT, min, TN - 1) &&
					HELPER(RIGHT, TN + 1, max));
	}
	return (0);
}

/**
 * binary_tree_is_avl - checks if a tree is avl
 * @tree: tree to check
 * Return:  1 is avl| 0 not avl
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (HELPER(tree, INT_MIN, INT_MAX));
}

/**
 * binary_tree_height - calculates the height of a binary tree
 * @tree: root of tree
 * Return: height of tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int left_path = 0, right_path = 0;

	if (tree == NULL)
		return (0);
	left_path = binary_tree_height(tree->left);
	right_path = binary_tree_height(tree->right);

	if (left_path >= right_path)
		return (left_path + 1);
	return (right_path + 1);
}
