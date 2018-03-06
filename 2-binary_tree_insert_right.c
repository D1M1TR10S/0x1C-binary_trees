#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a right child node in a binary tree
 * @parent: Node that child is being attached to
 * @value: Number being held by the new node
 * Return: Pointer to new node
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
        binary_tree_t *new_node;

        if (parent == NULL)
                return (NULL);

        new_node = malloc(sizeof(binary_tree_t));
        if (new_node == NULL)
                return (NULL);

        new_node->parent = parent;
        new_node->n = value;
        new_node->left = NULL;
        new_node->right = parent->right;
        if(new_node->right != NULL)
                new_node->right->parent = new_node;
        parent->right = new_node;
        return (new_node);
}
