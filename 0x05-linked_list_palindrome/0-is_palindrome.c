#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


/**
 * reverse_list - adds a new node at the end of a listint_t list
 * @head: pointer to pointer of first node of listint_t list
 * @auxl: pointer to pointer of first node of listint_t list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int reverse_list(listint_t *head, listint_t **auxl)
{
	int pal;

	if (head)
	{
		pal = reverse_list(head->next, auxl);
		if (pal == 0)
			return (pal);
		pal = (head->n == (*auxl)->n);
		*auxl = (*auxl)->next;
		return (pal);
	}
	else
		return (1);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to pointer of first node of listint_t list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	int pal;

	if (head && *head)
		pal = reverse_list(*head, head);
	return (pal);
}
