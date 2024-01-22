#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * max_heapify - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t largest, left, right

	while ((left = 2 * root + 1) < base)
	{
		right = 2 * root + 2;
		largest = roo

		if (array[left] > array[largest] && left < base)
			largest = left;

		if (right < base && array[right] > array[largest])
			largest = right;

		if (largest != root)
		{
			swap_ints(array + root, array + largest);
			print_array(array, size);
			root = largest;
		}
		else
		{
			break;
		}
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm using while loops. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int j;

	if (array == NULL || size < 2)
		return;

	for (j = size / 2 - 1; j >= 0; j--)
		max_heapify(array, size, size, j);

	for (j = size - 1; j > 0; j--)
	{
		swap_ints(array, array + j);
		print_array(array, size);
		max_heapify(array, size, j, 0)
	}
}
