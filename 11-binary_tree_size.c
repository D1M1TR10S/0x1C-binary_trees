#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_size - Return the size of a binary tree
 * @tree: Pointer to root node
 * Return: 0 on failure and 1 on success
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
        if (tree == NULL)
                return (0);

        if (tree->left == NULL && tree->right == NULL)
                return (1);
        
        return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
