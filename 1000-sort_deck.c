#include "deck.h"

/**
 * Swap - swaps two doubly linked list nodes
 * @A: the first node
 * @B: the second node
 */
void Swap(deck_node_t *A, deck_node_t *B)
{
if (A->prev != NULL)
A->prev->next = B;
if (B->next != NULL)
B->next->prev = A;
A->next = B->next;
B->prev = A->prev;
A->prev = B;
B->next = A;
}

/**
 * Compare - compares cards Ace-King tnen by Spades-Diamonds
 * @A: the first card
 * @B: the second card
 *Return: comparison result 0: equal or 1: lesser
 */
int Compare(const card_t *A, const card_t *B)
{
char *str_a = (char *)A->value, *str_b = (char *)B->value, *str;
char *values[] = {"King", "Queen", "Jack", "10", "9", "8", "7",
"6", "5", "4", "3", "2", "Ace"};
int a = 0, b = 0, i;

for (i = 0; i < 13; i++)
{
for (str = values[i]; *str_a && *str == *str_a; ++str_a, ++str)
;
if (*str_a == 0 && *str == 0)
{
a = i;
break;
}
}

for (i = 0; i < 13; i++)
{
for (str = values[i];  *str_b && *str == *str_b; ++str_b, ++str)
;
if (*str_b == 0 && *str == 0)
{
b = i;
break;
}
}

if (A->kind == B->kind)
return (a < b);
return (A->kind > B->kind);
}

/**
 * insertion_sort_list - sorts in ascending order using insertion sort
 * @list: pointer to doubly linked list node
 */
void insertion_sort_list(deck_node_t **list)
{
deck_node_t *curr, *head;
if (list == NULL || (*list)->next == NULL || (*list) == NULL)
return;
head = (*list)->next;
while (head != NULL)
{
curr = head;
head = head->next;
while (curr && curr->prev != NULL)
{
if (Compare(curr->prev->card, curr->card))
{
Swap(curr->prev, curr);
if (curr->prev == NULL)
*list = curr;
}
else
curr = curr->prev;
}
}
}

/**
 * sort_deck - sorts a deck of cards.
 * @deck: pointer to deck of cards i.e. doubly linked list
 */
void sort_deck(deck_node_t **deck)
{
insertion_sort_list(deck);
}
