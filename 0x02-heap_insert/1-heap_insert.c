#include "binary_trees.h"

/**
  *heap_insert - inserts a value into a Max Binary Heap
  *@root: double pointer to the root node of the Heap
  *@value: value stored in the node to be inserted
  *Return: a pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node = NULL;
	int aux;

	if (root)
	{
		if (*root)
		{
			node = last_node(*root, value);
			if (node)
			{
				while (node->parent && node->parent->n < node->n)
				{
					aux = node->n;
					node->n = node->parent->n;
					node->parent->n = aux;
					node = node->parent;
				}
				return (node);
			}
		}
		else
		{
			*root = binary_tree_node(NULL, value);
			return (*root);
		}
	}
	return (NULL);
}

/**
  *push - a value into the queue
  *@last: element of queue
  *@node: to insert
  *Return: a pointer to the inserted node, or NULL on failure
*/
queue *push(queue *last, heap_t *node)
{
	queue *q = malloc(sizeof(queue));

	if (q)
	{
		q->node = node;
		q->next = NULL;
		if (last)
			last->next =  q;
		return (q);
	}
	return (NULL);
}

/**
  *update - queue pointers
  *@q: queue
  *Return: a pointer to the queue
*/
queue *update(queue *q)
{
	queue *tmp;

	tmp = q;
	q = q->next;
	free(tmp);
	return (q);
}


/**
  *last_node - inserts node on the last position of a heap
  *@root: pointer to the root node of the heap
  *@value: value stored in the node to be inserted
  *Return: a pointer to the inserted node, or NULL on failure
*/
heap_t *last_node(heap_t *root, int value)
{
	queue *q, *last;
	heap_t *node = NULL;

	q = push(NULL, root);
	if (q)
	{
		last = q;
		while (q)
		{
			if (node)
				q = update(q);
			else if (q->node->left && q->node->right)
			{
				last = push(last, q->node->left);
				if (last)
				{
					last = push(last, q->node->right);
					if (last)
						q = update(q);
					else
						return (NULL);
				}
				else
					return (NULL);
			}
			else if (!q->node->left)
			{
				node = binary_tree_node(q->node, value);
				q->node->left = node;
			}
			else
			{
				node = binary_tree_node(q->node, value);
				q->node->right = node;
			}
		}
		return (node);
	}
	return (NULL);
}
