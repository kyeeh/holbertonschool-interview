#include "search.h"
/**
  * search_at -  value checker
  *
  * @node: is a pointer to the next list to search in
  * @value: is the value to search for
  *
  * Return: pointer to the node with value or NULL
 */
skiplist_t *search_at(skiplist_t *node, int value)
{
	for (; node; node = node->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
		if (node->n == value)
			return (node);
	}
	return (NULL);
}


/**
  * linear_skip -  searches for a value in a sorted skip int list
  *
  * @list: is a pointer to the head
  * @value: value to search
  *
  * Return: pointer to the value or NULL
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node1, *node2, *node3;

	if (list)
	{
		node1 = list;
		while (node1)
		{
			if (node1->express == NULL)
			{
				node2 = node1->express;
				for (node3 = list; node3; node3 = node3->next)
					if (node3->next == NULL)
					{
						printf("Value found between indexes [%lu] and [%lu]\n",
							node1->index, node3->index);
						break;
					}
				break;
			}
			if (node1->express->n >= value)
			{
				node2 = node1->express;
				printf("Value checked at index [%lu] = [%d]\n", node2->index, node2->n);
				printf("Value found between indexes [%lu] and [%lu]\n",
					node1->index, node2->index);
				break;
			}
			node1 = node1->express;
			printf("Value checked at index [%lu] = [%d]\n", node1->index, node1->n);
		}
		return (search_at(node1, value));
	}
	return (NULL);
}
