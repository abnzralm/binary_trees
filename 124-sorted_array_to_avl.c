 #include "binary_trees.h"

/**
 * create_tree - creates an AVL tree with recursion
 *
 * @node: pointer node
 * @array: input array of integers
 * @size: size of array
 * @mode: 1 to adding on the left, 2 to adding on the right
 * Return: no return
 */
void create_tree(avl_t **node, int *array, size_t size, int mode)
{
	size_t mid;

	if (size == 0)
		return;

	mid = (size / 2);
	mid = (size % 2 == 0) ? mid - 1 : mid;

	if (mode == 1)
	{
		(*node)->left = binary_tree_node(*node, array[mid]);
		create_tree(&((*node)->left), array, mid, 1);
		create_tree(&((*node)->left), array + mid + 1, (size - 1 - mid), 2);
	}
	else
	{
		(*node)->right = binary_tree_node(*node, array[mid]);
		create_tree(&((*node)->right), array, mid, 1);
		create_tree(&((*node)->right), array + mid + 1, (size - 1 - mid), 2);
	}
}

/**
 * sorted_array_to_avl - creates root node and calls
 *
 * @array: input array of integers
 * @size: size of array
 * Return: pointer to the root
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *rut;
	size_t mid;

	rut = NULL;

	if (size == 0)
		return (NULL);

	mid = (size / 2);

	mid = (size % 2 == 0) ? mid - 1 : mid;

	rut = binary_tree_node(rut, array[mid]);

	create_tree(&rut, array, mid, 1);
	create_tree(&rut, array + mid + 1, (size - 1 - mid), 2);

	return (rut);
}
