#include "sort.h"
#include <stdio.h>

/**
 * merge - Merges two subarrays in a given direction
 * @array: The array to merge
 * @low: Starting index of the subarray to be merged
 * @count: Size of the subarray to be merged
 * @dir: Sorting direction (1 for ascending, 0 for descending)
 */
static void merge(int *array, size_t low, size_t count, int dir)
{
    if (count > 1)
    {
        size_t k = count / 2;
        size_t i;

        for (i = low; i < low + k; i++)
        {
            if ((array[i] > array[i + k]) == dir)
            {
                int temp = array[i];
                array[i] = array[i + k];
                array[i + k] = temp;
            }
        }

        merge(array, low, k, dir);
        merge(array, low + k, k, dir);
    }
}

/**
 * bitonic_merge - Recursively sorts a bitonic sequence in given direction
 * @array: The array to sort
 * @low: Starting index of the subarray to be sorted
 * @count: Size of the subarray to be sorted
 * @dir: Sorting direction (1 for ascending, 0 for descending)
 */
static void bitonic_merge(int *array, size_t low, size_t count, int dir)
{
    if (count > 1)
    {
        size_t k = count / 2;

        printf("Merging [%lu/%lu] (%s):\n", count, count * 2, dir ? "UP" : "DOWN");
        print_array(array + low, count);

        bitonic_merge(array, low, k, 1);
        bitonic_merge(array, low + k, k, 0);
        merge(array, low, count, dir);

        printf("Result [%lu/%lu] (%s):\n", count, count * 2, dir ? "UP" : "DOWN");
        print_array(array + low, count);
    }
}

/**
 * bitonic_sort_recursive - Recursively sorts a bitonic sequence in ascending order
 * @array: The array to sort
 * @low: Starting index of the subarray to be sorted
 * @count: Size of the subarray to be sorted
 * @dir: Sorting direction (1 for ascending, 0 for descending)
 */
static void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir)
{
    if (count > 1)
    {
        size_t k = count / 2;

        printf("Merging [%lu/%lu] (%s):\n", count, count * 2, dir ? "UP" : "DOWN");
        print_array(array + low, count);

        bitonic_sort_recursive(array, low, k, 1);
        bitonic_sort_recursive(array, low + k, k, 0);
        bitonic_merge(array, low, count, dir);

        printf("Result [%lu/%lu] (%s):\n", count, count * 2, dir ? "UP" : "DOWN");
        print_array(array + low, count);
    }
}

/**
 * bitonic_sort - Sorts an array in ascending order using Bitonic sort algorithm
 * @array: The array to sort
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (size <= 1)
        return;

    bitonic_sort_recursive(array, 0, size, 1);
}

