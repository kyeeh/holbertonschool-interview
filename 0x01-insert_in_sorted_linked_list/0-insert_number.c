#include "lists.h"
/**
 * get_node_rec - get the nth-1 node of a listint_t linked list recursively.
 * @head: pointer to list.
 * @n: number of nodes acumlated as param.
 * @index: index of node to return.
 * Return: nth node.
 */
listint_t *get_node_rec(listint_t *head, int n)
{
	if ((head)->next && (head)->next->n < n)
        head = get_node_rec(head->next, n);
	return (head);
}
/**
 * inserts a number into a sorted singly linked list.
 * @head: double pointer to list.
 * @number: data for new node insertion.
 * Return: the address of the new node.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node, *tmp_node;

	new_node = malloc(sizeof(listint_t));
    new_node->n = number;
	if (head && *head)
	{
		if (new_node)
		{
			if (number <= (*head)->n)
            {
				new_node->next = *head;
                *head = new_node;
                return (new_node);
            }
            tmp_node = get_node_rec(*head, number);
            if (tmp_node)
            {
                new_node->next = tmp_node->next;
                tmp_node->next = new_node;
                return (new_node);
            }
		}
	}
    else
    {
		if (new_node)
		{
            *head = new_node;
            return (new_node);
        }
    }
	return (NULL);
}
