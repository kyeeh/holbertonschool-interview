#include "binary_trees.h"

/**
 * heap_size - get the size of heap
 * @heap: pointer to root
 * Return: size of the heap
 */
int heap_size(const heap_t *heap)
{
	size_t lft, rgt, size;

	if (!heap)
		return (0);
	lft = heap_size(heap->left);
	rgt = heap_size(heap->right);
	size = lft + rgt + 1;

	return (size);
}

/**
 * heap_search - helps to extract the root node
 * @heap: pointer to heap
 */
void heap_search(heap_t *heap)
{
	heap_t *node = heap, *child;
	int tmp;

	while (1)
	{
		if (!node->left)
			break;
		if (!node->right)
			child = node->left;
		else
			child = node->left->n > node->right->n ?
				node->left : node->right;
		if (node->n > child->n)
			break;
		tmp = node->n;
		node->n = child->n;
		child->n = tmp;
		node = child;
	}
}

/**
 * heap_extract - extracts top node of max binary heap
 * @heap: pointer to heap
 * Return: root node
 */
int heap_extract(heap_t **heap)
{
	int n, size, btw;
	heap_t *node, *root;

	if (heap || *heap)
	{
		root = *heap;
		n = root->n;
		size = heap_size(root);

		if (size == 1)
		{
			free(root);
			*heap = NULL;
			return (n);
		}

		for (btw = 1; btw <= size; btw <<= 1);
		btw >>= 2;

		for (node = root; btw > 0; btw >>= 1)
			node = size & btw ? node->right : node->left;
		root->n = node->n;

		if (node->parent->left == node)
			node->parent->left = NULL;
		else
			node->parent->right = NULL;

		free(node);
		heap_search(root);
		*heap = root;

		return (n);
	}
	return (0);
}
