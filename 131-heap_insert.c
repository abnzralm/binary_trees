#include "binary_trees.h"

/**
 * heap_insert - inserts a value in MBH
 * @root: a double pointer to the root node of the Heap to insert the value
 * @value: the value to store in the node to be inserted
 *
 * Return: a pointer to the created node
 *         NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new, *flip;
	int size, lefs, sb, bt, lvl, tpppp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	lefs = size;
	for (lvl = 0, sb = 1; lefs >= sb; sb *= 2, lvl++)
		lefs -= sb;
	/* sbtract all nodes except for bottom-most lvl */

	for (bt = 1 << (lvl - 1); bt != 1; bt >>= 1)
		tree = lefs & bt ? tree->right : tree->left;

	new = binary_tree_node(tree, value);
	lefs & 1 ? (tree->right = new) : (tree->left = new);

	flip = new;
	for (; flip->parent && (flip->n > flip->parent->n); flip = flip->parent)
	{
		tpppp = flip->n;
		flip->n = flip->parent->n;
		flip->parent->n = tpppp;
		new = new->parent;
	}

	return (new);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to measure the size of
 *
 * Return: size of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
