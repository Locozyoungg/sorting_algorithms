#include "deck.h"
#include <stdlib.h>

/**
 * _strcmp - Compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Return: Positive byte difference if s1 > s2
 *         0 if s1 == s2
 *         Negative byte difference if s1 < s2
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		return (*s1 - *s2);

	return (0);
}
/**
 * compare_cards - Comparison function for qsort to sort cards.
 * @a: Pointer to the first card.
 * @b: Pointer to the second card.
 *
 * Return: Negative value if a < b, 0 if a == b, positive value if a > b.
 */
int compare_cards(const void *a, const void *b)
{
	const card_t *card_a = (*(const deck_node_t **)a)->card;
	const card_t *card_b = (*(const deck_node_t **)b)->card;

	/* Compare kind first */
	if (card_a->kind != card_b->kind)
		return (card_a->kind - card_b->kind);

	/* If kinds are the same, compare values */
	return (_strcmp(card_a->value, card_b->value));
}
/**
 * sort_deck - Sort a deck of cards using qsort.
 * @deck: Pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
	size_t i;
	size_t count = 0;
	deck_node_t *current = *deck;
	deck_node_t **deck_array;

	/* Count the number of nodes in the deck */
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	/* Create an array of pointers to deck_node_t for qsort */
	deck_array = malloc(count * sizeof(deck_node_t *));

	if (deck_array == NULL)
		return;

	current = *deck;

	for (i = 0; i < count; i++)
	{
		deck_array[i] = current;
		current = current->next;
	}
	/* Use qsort to sort the array of pointers to deck_node_t */
	qsort(deck_array, count, sizeof(deck_node_t *), compare_cards);
	/* Update the doubly-linked list based on the sorted array */
	for (i = 0; i < count; i++)
	{
		deck_array[i]->prev = (i > 0) ? deck_array[i - 1] : NULL;
		deck_array[i]->next = (i < count - 1) ? deck_array[i + 1] : NULL;
	}
	/* Update the head of the doubly-linked list */
	*deck = (count > 0) ? deck_array[0] : NULL;
	/* Free the temporary array */
	free(deck_array);
}
