#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Tells user if a node is a leaf
 * @node: Node to be tested
 * Return: 0 on failure and 1 on success
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL || node->right != NULL)
		return (0);
	return (1);
}
