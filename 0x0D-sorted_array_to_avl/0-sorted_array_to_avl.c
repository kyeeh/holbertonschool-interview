#include "binary_trees.h"

/**
  *binary_tree_node - creates a binary tree node
  *@parent: pointer to the parent node of the node to create
  *@value: is the value to put in the new node
  *Return: a pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (node)
	{
		node->n = value;
		node->parent = parent;
		node->left = NULL;
		node->right = NULL;
		return (node);
	}
	return (NULL);
}

/**
  * insert_node - builds an AVL tree from an array
  * @arr: The array to be inserted
  * @parent: the parent of the new node
  * @start: the first node to insert
  * @end: the last node to insert
  * Return: a pointer to the new avl on success or NULL on failure
 */
avl_t *insert_node(int *arr, size_t start, size_t end, avl_t *parent)
{
	size_t middle;
	avl_t *root;

	if (start > end)
		return (NULL);

	middle = (start + end) / 2;
	root = binary_tree_node(parent, arr[middle]);
	if (!root)
		return (NULL);

	if (middle != start)
		root->left = insert_node(arr, start, middle - 1, root);

	if (middle != end)
		root->right = insert_node(arr, middle + 1, end, root);

	return (root);
}

/**
  * sorted_array_to_avl - builds an AVL tree from an array
  * @array: initial array
  * @size: Array's size
  * Return: AVL binary tree or NULL
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;

	if (array && size)
	{
		root = insert_node(array, 0, size - 1, NULL);
		return (root);
	}
	return (NULL);
}
