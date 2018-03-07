#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_nodes - Return the number of nodes with at least one child
 * @tree: Pointer to root node
 * Return: Number of nodes with a child
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
        if (tree == NULL || (tree->left == NULL && tree->right == NULL))
                return (0);
        else
                return (binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right) + 1);
}
