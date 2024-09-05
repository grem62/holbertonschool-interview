#include "sort.h"

/**
 * heapify - Maintains the max-heap property.
 * @array: The array to sort.
 * @start: The starting index.
 * @end: The ending index.
 * @size: The size of the array.
 */
void heapify(int *array, int start, int end, size_t size)
{
	int root, child, swap, temp;

	root = start;
	while ((2 * root + 1) <= end)
	{
		child = 2 * root + 1;
		swap = root;
		/* Find the largest element among the root and its children */
		if (array[swap] < array[child])
			swap = child;
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;
		/* If the root is already the largest element, stop */
		if (swap == root)
			return;

		/* Swap  the root with the largest child */
		temp = array[root];
		array[root] = array[swap];
		array[swap] = temp;
		/* Print the current array state */
		print_array(array, size);

		root = swap;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i, temp;

	/* Check if the array is valid and has more than one element */
	if (array == NULL || size < 2)
		return;

	/* Build the max heap */
	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, i, size - 1, size);

	/* Sort the array */
	for (i = size - 1; i > 0; i--)
	{
		/* Swap the root with the last element */
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		/* Print the current array state */
		print_array(array, size);
		/* Heapify the new root */
		heapify(array, 0, i - 1, size);
	}
}
