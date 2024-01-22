#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - Merges two subarrays of 'array'.
 * @array: The array to be sorted.
 * @l: Left index of the subarray.
 * @m: Middle index of the subarray.
 * @r: Right index of the subarray.
 */
static void merge(int *array, size_t l, size_t m, size_t r)
{
    size_t i, j, k;
    size_t n1 = m - l + 1;
    size_t n2 = r - m;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    if (!L || !R)
    {
        free(L);
        free(R);
        return;
    }

    for (i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the
 *              Merge sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
    if (size > 1)
    {
        size_t m = size / 2;
        size_t i;

        int *L = malloc(m * sizeof(int));
        int *R = malloc((size - m) * sizeof(int));

        if (!L || !R)
        {
            free(L);
            free(R);
            return;
        }

        for (i = 0; i < m; i++)
            L[i] = array[i];

        for (i = m; i < size; i++)
            R[i - m] = array[i];

        merge_sort(L, m);
        merge_sort(R, size - m);
        merge(array, 0, m - 1, size - 1);

        free(L);
        free(R);
    }
}

