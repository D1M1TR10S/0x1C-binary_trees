#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * powpow - Power function
 * @base: Number being powered
 * @power: Number being raised to
 * Return: Result
 */

int powpow(int base, size_t power)
{
	if (power > 0)
		return (base * powpow(base, power - 1));
	else
		return (1);
}

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
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to root node
 * Return: 1 if tree is perfect, else 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height, size;
	int sum = 0;

	if (tree == NULL)
		return (0);

	size = binary_tree_size(tree);
	height = binary_tree_height(tree);

	while (height >= 0)
	{
		sum += powpow(2, height);
		height--;
	}
	if (sum == size)
		return (1);
	else
		return (0);
}
