#include "sort.h"

/**
 *swap - Swap 2 nodes in listint_t
 *@list: address to the head of the ll.
 *@node1: address to the first node.
 *@node2: second node to swap.
 */
void swap(listint_t **list, listint_t **node1, listint_t **node2)
{
	(*node1)->next = (*node2)->next;
	if (!(*node2)->next)
		(*node2)->next->prev = *node1;
	(*node2)->next = *node1;
	(*node2)->prev = (*node1)->prev;
	if (!(*node1)->prev)
		(*node1)->prev->next = (*node2);
	else
		*list = (*node2);
	(*node1)->prev = (*node2);
	*node1 = (*node2)->prev;
}

/**
 *insertion_sort_list - Insert sorting to a doubly linked list
 *@list: Address of  the head of a doubly-linked list of integers.
 *Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *z, *a, *c;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (a = (*list)->next; a != NULL; a = c)
	{
		c = a->next;
		z = a->prev;
		while (z != NULL && a->n < z->n)
		{
			swap(list, &z, &a);
			print_list((const listint_t *) *list);
		}
	}
}
