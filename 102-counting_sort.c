#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *                 the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int *counting_array;
	int max;

	if (array == NULL || size < 2)
		return;

	/* Find the maximum value in the array */
	max = array[0];

	for (i = 1; i < size; i++)
		if ((size_t)array[i] > (size_t)max)
			max = array[i];
	/* separate declaration from code */
	counting_array = (int *)malloc((max + 1) * sizeof(int));

	if (counting_array == NULL)
		return;

	/* Populate the counting array */
	for (i = 0; i <= (size_t)max; i++)
		counting_array[i] = 0;

	for (i = 0; i < size; i++)
		counting_array[(size_t)array[i]]++;

	/* separate declaration from code */
	i = 0;

	while (i <= (size_t)max)
	{
		if (counting_array[i] > 0)
		{
			array[i] = (int)i;
			counting_array[i]--;
			i++;
		}
		else
		{
			i++;
		}
	}
	/* Free the counting array */
	free(counting_array);
}
