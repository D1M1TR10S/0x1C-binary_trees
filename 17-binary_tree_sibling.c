#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_sibling - Return the sibling of a node
 * @node: Pointer to node being checked
 * Return: Return address of sibling node
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *check;

	if (node == NULL || node->parent == NULL)
		return (0);

	check = node->parent;
	if (node != check->left && check->left != NULL)
		return (check->left);
	if (node != check->right && check->right != NULL)
		return (check->right);
	return (NULL);
}
