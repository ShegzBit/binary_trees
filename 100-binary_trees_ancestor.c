#include "binary_trees.h"
#define DEPTH binary_tree_depth

/**
 * binary_tree_depth - finds how deep below the root a node is
 * @tree: node to determine root
 * Return: depth of node tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL || tree->parent == NULL)
		return (0);
	return (binary_tree_depth(tree->parent) + 1);
}

/**
 * binary_trees_ancestor - locates the nearest ancestor to both nodes
 * @first: first node
 * @second: second node
 * Return: lowest common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((void *)first);
	if (DEPTH(first) > DEPTH(second))
		return (binary_trees_ancestor(first->parent, second));
	else if (DEPTH(first) < DEPTH(second))
		return (binary_trees_ancestor(first, second->parent));
	return (binary_trees_ancestor(first->parent, second->parent));
}
