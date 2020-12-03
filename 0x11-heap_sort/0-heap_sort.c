#include "sort.h"

/**
 * swap - swaps two numbers
 * @a: first pointer
 * @b: second pointer
 * @array: list of integers
 * @size: length of array
 */
void swap(int *array, int *a, int *b, int size)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	print_array(array, size);
}

/**
 * heapify - have the highest element at root
 * @array: tree structure
 * @n: size of the array each iteration after deleting positions
 * @i: root
 * @size: size of the array
 */
void heapify(int *array, int n, int i, int size)
{
	int largest, left, right;

	largest = i;
	left = (2 * i) + 1;
	right = (2 * i) + 2;

	if (left < n && array[left] > array[largest])
		largest = left;

	if (right < n && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(array, &array[i], &array[largest], size);
		heapify(array, n, largest, size);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 *
 * @array: int array to be sort
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (!array)
		return;

	for (i = size / 2; i > 0; i--)
		heapify(array, size, i - 1, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(array, &array[0], &array[i], size);
		heapify(array, i, 0, size);
	}
}