#include "sort.h"

/**
 *swap - Swap 2 nodes in a listint_t doubly-linked list.
 *@hug: address to the head of the doubly-linked list.
 *@num1: address to the first node to swap.
 *@num2: second node to swap.
 */
void swap(listint_t **hug, listint_t **num1, listint_t **num2)
{
	(*num1)->next = (*num2)->next;
	if ((*num2)->next != NULL)
		(*num2)->next->prev = *num1;
	(*num2)->prev = (*num1)->prev;
	(*num2)->next = *num1;
	if ((*num1)->prev != NULL)
		(*num1)->prev->next = (*num2);
	else
		*
		hug = (*num2);
	(*num1)->prev = (*num2);
	*num1 = (*num2)->prev;
}

/**
 *insertion_sort_list - Insert sorts a doubly linked list
 *@list: Address of  the head of a doubly-linked list of integers.
 *
 *Description: Prints the list after each swap.
 *Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *m, *z, *a;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (m = (*list)->next; m != NULL; m = a)
	{
		a = m->next;
		z = m->prev;
		while (z != NULL && m->n < z->n)
		{
			swap(list, &z, &m);
			print_list((const listint_t *) *list);
		}
	}
}
