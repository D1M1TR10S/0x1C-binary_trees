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


/**
 * b_helper - Indexes all the nodes ina a binary tree
 * @tree: Pointer to node
 * @index: First index of binary tree
 * @size: Number of nodes in the binary tree
 * Return: 0 on failure and 1 on success
 */

int b_helper(const binary_tree_t *tree, size_t index, size_t size)
{
	int left, right;

	if (tree == NULL)
		return (1);	

	if (index > size)
		return (0);

	left = b_helper(tree->left, (index * 2) + 1, size);
	right = b_helper(tree->right, (index * 2) + 2, size);

	if (left == 0 || right == 0)
		return (0);
	return (1);
}

/**
 * binary_tree_is_complete - See if a binary tree is complete 
 * @tree: Pointer to node
 * Return: 1 if complete, 0 if not
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int result;

	if (tree == NULL)
		return (0);

	result = b_helper(tree, 0, binary_tree_size(tree) - 1);
	return (result);	
}
