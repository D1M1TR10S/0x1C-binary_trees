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

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to root node
 * Return: 1 if full, else return 0
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
        int left, right;

        if (tree == NULL)
                return (0);
        if (tree->left == NULL && tree->right == NULL)
                return (1);
        if (tree->left == NULL && tree->right != NULL)
                return (0);
        if (tree->left != NULL && tree->right == NULL)
                return (0);

        left = binary_tree_is_full(tree->left);
        right = binary_tree_is_full(tree->right);

        if (left == 0 || right == 0)
                return (0);
        else
                return (1);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to root node
 * Return: 1 if tree is perfect, else 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
        int left, right;

        if (tree == NULL) 
                return (0);
        
        binary_tree_is_perfect(tree->left);
        binary_tree_is_perfect(tree->right);

        if (binary_tree_height(tree->left) != binary_tree_height(tree->right))
                return (0);

        return (binary_tree_is_full(tree));
}
