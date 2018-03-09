#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_depth - Return the depth of node in a binary tree
 * @node: Pointer to node
 * Return: 0 on failure and 1 on success
 */

size_t binary_tree_depth(const binary_tree_t *node)
{
	size_t depth = 0;

	if (node == NULL)
		return (0);

	while (node->parent != NULL)
	{
		node = node->parent;
		depth++;
	}
	return (depth);
}

/**
 * binary_trees_ancestor - Return the common ancestor of two nodes
 * @first: Pointer to first node being compared
 * @second: Pointer to second node
 * Return: Pointer to lowest common ancestor
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	binary_tree_t *node_1 = (binary_tree_t *)first;
	binary_tree_t *node_2 = (binary_tree_t *)second;
	size_t first_dep;
	size_t second_dep;

	if (first == NULL || second == NULL)
		return (NULL);

	first_dep = binary_tree_depth(first);
	second_dep = binary_tree_depth(second);

	while (first_dep > second_dep)
	{
		node_1 = node_1->parent;
		first_dep--;
	}
	while (second_dep > first_dep)
	{
		node_2 = node_2->parent;
		second_dep--;
	}
	while (node_1 != node_2)
	{
		node_1 = node_1->parent;
		node_2 = node_2->parent;
	}
	return (node_1);
}
