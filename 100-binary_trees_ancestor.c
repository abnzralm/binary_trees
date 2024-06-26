#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: If no common ancestors return NULL.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *mum, *pup;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	mum = first->parent, pup = second->parent;
	if (first == pup || !mum || (!mum->parent && pup))
		return (binary_trees_ancestor(first, pup));
	else if (mum == second || !pup || (!pup->parent && mum))
		return (binary_trees_ancestor(mum, second));
	return (binary_trees_ancestor(mum, pup));
}
