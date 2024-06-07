#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Left-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pvt, *tpp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	pvt = tree->right;
	tpp = pvt->left;
	pvt->left = tree;
	tree->right = tpp;
	if (tpp != NULL)
		tpp->parent = tree;
	tpp = tree->parent;
	tree->parent = pvt;
	pvt->parent = tpp;
	if (tpp != NULL)
	{
		if (tpp->left == tree)
			tpp->left = pvt;
		else
			tpp->right = pvt;
	}

	return (pvt);
}
