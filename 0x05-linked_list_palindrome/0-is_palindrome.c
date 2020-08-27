#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


/**
 * reverse_list - adds a new node at the end of a listint_t list
 * @head: pointer to pointer of first node of listint_t list
 * @auxl: pointer to pointer of first node of listint_t list
 * Return: void
 */
void reverse_list(listint_t *head, listint_t **auxl)
{
	if (head)
	{
		reverse_list(head->next, auxl);
		add_nodeint_end(auxl, (head)->n);
	}
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to pointer of first node of listint_t list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	int pal = 1;
	listint_t *node, *temp, *auxl = NULL;

	if (head)
	{
		if (*head)
		{
			reverse_list(*head, &auxl);
			node = *head;
			temp = auxl;
			while (node != NULL)
			{
				if (node->n == temp->n)
				{
					node = node->next;
					temp = temp->next;
				}
				else
					return (0);
			}
		}
	}
	else
		pal = 0;
	return (pal);
}
