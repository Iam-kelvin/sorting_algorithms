#include "sort.h"

/**
 * Swap - swaps two doubly linked list nodes
 * @A: the first node
 * @B: the second node
 */
void Swap(listint_t **A, listint_t **B)
{
if ((*A)->prev)
(*A)->prev->next = *B;
if ((*B)->next)
(*B)->next->prev = *A;

(*A)->next = (*B)->next;
(*B)->prev = (*A)->prev;
(*B)->next = *A;
(*A)->prev = *B;
}


/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * using the Cocktail shaker sort
 * @list: a doubly linked list of integers
 * not allowed to modify the integer n of a node, You have to swap the nodes
 */
void cocktail_sort_list(listint_t **list)
{
int flag;
listint_t *head, *tail;
if (!list || !*list)
return;

head = *list;
do {
flag = 0;
while (head->next)
{
tail = head->next;
if (head->n > tail->n)
{
Swap(&head, &tail);
if (!tail->prev)
*list = tail;
print_list(*list);
flag = 1;
}
else
head = head->next;
}
tail = head->prev;
while (tail->prev)
{
head = tail->prev;
if (tail->n < head->n)
{
if (!head->prev)
*list = tail;
Swap(&head, &tail);
print_list(*list);
flag = 1;
}
else
tail = tail->prev;
}
} while (flag);
}
