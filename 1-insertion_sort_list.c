#include "sort.h"

/**
 * insertion_sort_list - is a simple sorting algorithm that builds
 * the final sorted array (or list) one item at a time.
 *
 * @list: List of an array of integers.
 *
 * Return: Void Function
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = *list, *curr, *left;

	if (!list || !(*list)->next)
		return;

	curr = tmp->next;
	while (curr)
	{
		left = curr;
		while (left->prev)
		{
			tmp = left->prev;
			if (tmp->n > left->n)
			{

				tmp->next = left->next;
				if (!curr->next)
					tmp->next = NULL;
				else
					left->next->prev = tmp;

				if (!tmp->prev)
					*list = left;
				else
					tmp->prev->next = left;
				left->prev = tmp->prev;
				left->next = tmp;
				tmp->prev = left;
				print_list(*list);
				continue;
			}
			left = left->prev;
		}
		curr = curr->next;
	}
}

