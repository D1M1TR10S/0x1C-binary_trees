#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_height - Return the height of node in a binary tree
 * @tree: Pointer to node
 * Return: 0 on failure and 1 on success
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
        size_t l_height, r_height;
        if ((tree == NULL) || (tree->left == NULL && tree->right == NULL))
                return (0);

        l_height = binary_tree_height(tree->left) + 1;
        r_height = binary_tree_height(tree->right) + 1;
        if (l_height >= r_height)
                return (l_height);
        else
                return (r_height);
}
