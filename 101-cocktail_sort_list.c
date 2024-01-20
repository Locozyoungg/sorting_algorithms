#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the doubly linked list
 * @node1: First node to swap
 * @node2: Second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    if (node1->prev)
        node1->prev->next = node2;
    else
        *list = node2;

    if (node2->next)
        node2->next->prev = node1;

    node1->next = node2->next;
    node2->prev = node1->prev;
    node1->prev = node2;
    node2->next = node1;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using the Cocktail Shaker sort algorithm
 * @list: Pointer to the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped;
    listint_t *current, *temp;

    if (list == NULL || *list == NULL)
        return;

    do {
        swapped = 0;
        for (current = *list; current->next != NULL; current = current->next)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(list, current, current->next);
                print_list(*list);
                swapped = 1;
            }
        }

        if (!swapped)
            break;

        swapped = 0;
        for (temp = current; temp->prev != NULL; temp = temp->prev)
        {
            if (temp->n < temp->prev->n)
            {
                swap_nodes(list, temp->prev, temp);
                print_list(*list);
                swapped = 1;
            }
        }

    } while (swapped);
}

