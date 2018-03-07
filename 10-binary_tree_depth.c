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
