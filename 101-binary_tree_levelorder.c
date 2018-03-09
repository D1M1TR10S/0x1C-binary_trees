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
  * open_binary_level - Prints each level of a binary tree
  * @tree: the pointer to the root of the tree
  * @func: the function to print the node's number
  * @level: The number of times to recurse
  * Return: Nothing, void
  */

void open_binary_level(const binary_tree_t *tree,
void (*func)(int), size_t level)
{
	if (level == 0)
		func(tree->n);

	if (tree->left == NULL && tree->right == NULL)
		return;

	if (level > 0)
	{
		open_binary_level(tree->left, func, level - 1);
		open_binary_level(tree->right, func, level - 1);
	}
}

/**
  * binary_tree_levelorder - Prints the binary tree out level by level
  * starting at 0
  * @tree: The binary tree to print
  * @func: The function to print the node's number
  * Return: nothing, void
  */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t level = 0;
	size_t height;

	if (tree == NULL || func == NULL)
		return;

	height = binary_tree_height(tree);

	while (level <= height)
	{
		open_binary_level(tree, func, level);
		level++;
	}
}
