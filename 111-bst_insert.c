#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a bst.
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *crt, *nw;

	if (tree != NULL)
	{
		crt = *tree;

		if (crt == NULL)
		{
			nw = binary_tree_node(crt, value);
			if (nw == NULL)
				return (NULL);
			return (*tree = nw);
		}

		if (value < crt->n)
		{
			if (crt->left != NULL)
				return (bst_insert(&crt->left, value));

			nw = binary_tree_node(crt, value);
			if (nw == NULL)
				return (NULL);
			return (crt->left = nw);
		}
		if (value > crt->n)
		{
			if (crt->right != NULL)
				return (bst_insert(&crt->right, value));

			nw = binary_tree_node(crt, value);
			if (nw == NULL)
				return (NULL);
			return (crt->right = nw);
		}
	}
	return (NULL);
}
