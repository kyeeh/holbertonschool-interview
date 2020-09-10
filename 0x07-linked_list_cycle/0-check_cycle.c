#include "lists.h"


/**
 * check_cycle - checks if a singly linked list has a cycle in it.
 * @list: memory pointer to the first element of the list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *init, *last;

	if (list)
	{
		init = list;
		last = list->next;
		while (init && last && last->next)
		{
			if (init == last)
				return (1);
			init = init->next;
			last = last->next->next;
		}
	}
	return (0);
}
