#include "sort.h"

/**
 * insertion_sort_list - sort a doubly linked list using insertion sort algorithm
 * @list: list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *nod, *temp;

	if (list == NULL || (*list)->next == NULL)
		return;
	nod = *list;
	while (nod)
	{
		while (nod->next && (nod->n > nod->next->n))
		{
			temp = nod->next;
			nod->next = temp->next;
			temp->prev = nod->prev;
			if (nod->prev != NULL)
				nod->prev->next = temp;
			if (temp->next != NULL)
				temp->next->prev = nod;
			nod->prev = temp;
			temp->next = nod;
			if (temp->prev)
				nod = temp->prev;
			else
				*list = temp;
			print_list(*list);
		}
		nod = nod->next;
	}
}
