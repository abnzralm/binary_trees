#include "binary_trees.h"

/**
 * array_to_heap - builds a Max bin Heap tree from an array
 * @array: a pointer to the first element of the array to be converted
 * @size: the number of element in the array
 *
 * Return: a pointer to the root node of the created bin Heap
 *         NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int i;
	heap_t *rooot = NULL;

	for (i = 0; i < size; i++)
		heap_insert(&rooot, array[i]);

	return (rooot);
}
