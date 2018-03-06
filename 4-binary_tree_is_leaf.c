#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Tells user if a node is a leaf
 * @node: Node to be deleted
 * Return: 0 on failure and 1 on success
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
        if (node == NULL)
                return (0);
        if (node->left == NULL && node->right == NULL)
                return (1);
        else
                return (0);
}
