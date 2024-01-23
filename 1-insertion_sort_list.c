#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the Insertion sort algorithm.
 *
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *prev, *temp;

    if (!list || !*list || !(*list)->next)
        return;

    current = (*list)->next;

    while (current)
    {
        temp = current;

        while (temp->prev && temp->n < temp->prev->n)
        {
            prev = temp->prev;

            if (temp->next)
                temp->next->prev = prev;
            else
                prev->next = NULL;

            temp->prev = prev->prev;
            temp->next = prev;
            prev->prev = temp;

            if (temp->prev)
                temp->prev->next = temp;
            else
                *list = temp;

            print_list(*list);
        }

        printf("Moving to next node...\n");
        current = current->next;
    }
}

