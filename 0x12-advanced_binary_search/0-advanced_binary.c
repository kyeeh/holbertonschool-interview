#include "search_algos.h"
/**
 * print_array - Entry point
 *
 * @array: Array
 * @fst: Size of array
 * @lst: Value to find
 * Return: EXIT_SUCCESS
 */
void print_array(int *array, int fst, int lst)
{
	int i;

	printf("Searching in array: ");
	for (i = fst; i < lst; i++)
		printf("%d, ", array[i]);
	printf("%d", array[i]);
	printf("\n");
}

/**
 * rec_abs - Recursive advanced binary search
 * @array: Array
 * @fst: fst element of array
 * @lst: lst element of array
 * @val: val to find
 * Return: EXIT_SUCCESS
 */

int rec_abs(int *array, size_t fst, size_t lst, int val)
{
	size_t hlf;

	if (fst < lst)
	{
		hlf = fst + (lst - fst) / 2;
		print_array(array, (int)fst, (int)lst);
		if (array[hlf] >= val)
			return (rec_abs(array, fst, hlf, val));
		else
			return (rec_abs(array, hlf + 1, lst, val));
				return ((int)(hlf));
	}
	if (array[fst] == val)
		return (fst);
	print_array(array, (int)fst, (int)lst);
	return (-1);
}


/**
 * advanced_binary - Entry point
 *
 * @array: Array
 * @size: Size of array
 * @value: Value to find
 * Return: EXIT_SUCCESS
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t fst;
	size_t lst;

	if (!array)
		return (-1);

	fst = 0;
	lst = size - 1;
	return (rec_abs(array, fst, lst, value));

}

