#include "sort.h"
#include <stdlib.h>

/**
 * getMax - Get the maximum value in an array
 * @array: The array to find the maximum value
 * @size: Size of the array
 * Return: The maximum value
 */
int getMax(int *array, size_t size)
{
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

/**
 * countingSort - Sort an array using counting sort based on the significant place
 * @array: The array to sort
 * @size: Size of the array
 * @exp: The significant place to consider
 */
void countingSort(int *array, size_t size, int exp)
{
    int *output = malloc(size * sizeof(int));
    int count[10] = {0};
    size_t i;

    if (output == NULL)
        return;

    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size - 1; i < size; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (i = 0; i < size; i++)
        array[i] = output[i];

    print_array(array, size);
    free(output);
}

/**
 * radix_sort - LSD Radix sort algorithm
 * @array: The array to sort
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
    int max = getMax(array, size);
    size_t exp;

    for (exp = 1; max / exp > 0; exp *= 10)
        countingSort(array, size, exp);
}

