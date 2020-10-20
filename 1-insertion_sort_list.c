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
	listint_t *tmp = *list, *tmp1 = tmp->next;
	int index = 0, i;

	if (*list == NULL || list == NULL)
		return;
	if ((*list)->next == NULL && (*list)->prev == NULL)
		return;
	while (tmp1 != NULL)
	{
		if (tmp->n > tmp1->n)
		{
			tmp1->prev = tmp->prev;
			tmp->next = tmp1->next;
			tmp->prev = tmp1;
			tmp1->next = tmp;
			if (tmp1->prev == NULL)
			{
				if (tmp->next != NULL)
					tmp->next->prev = tmp;
				*list = tmp1;
			}
			else if (tmp->next == NULL && tmp1->prev != NULL)
				tmp1->prev->next = tmp1;
			else if (tmp1->prev != NULL && tmp->next != NULL)
			{
				tmp->next->prev = tmp;
				tmp1->prev->next = tmp1;
			}
			print_list(*list);
			tmp = tmp1->prev;
			while (tmp != NULL)
			{
				if (tmp->n > tmp1->n)
				{
					tmp1->prev = tmp->prev;
					tmp->next = tmp1->next;
					tmp->prev = tmp1;
					tmp1->next = tmp;
					if (tmp1->prev == NULL)
					{
						tmp->next->prev = tmp;
						*list = tmp1;
					}
					else
					{
						tmp->next->prev = tmp;
						tmp1->prev->next = tmp1;
					}
					print_list(*list);
				}
				tmp1 = tmp;
				tmp = tmp->prev;
			}
		}
		tmp = *list;
		index += 1;
		for (i = 0; index > i; i++)
		{
			tmp = tmp->next;
			tmp1 = tmp->next;
		}
	}
}
