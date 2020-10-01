#include "slide_line.h"

/**
 * left_slider - slides and merges an array of integers to the left
 * @line: points to an array of integers
 * @size: Number of elements in array
 * Return: 1 success, 0 Fail
 */
int left_slider(int *line, size_t size)
{
	int i, j, index = 0;

	for (i = 0; i < (int)size && index < (int)size; i++)
	{
		if (line[i] > 0)
		{
			if (index != i)
			{
				line[index] = line[i];
				line[i] = 0;
			}
			for (j = i + 1; j < (int)size && index < (int)size; j++)
			{
				if (line[j] == line[index])
				{
					line[index] += line[j];
					line[j] = 0;
					break;
				}
			}
			index++;
		}
	}
	return (1);
}

/**
 * right_slider - slides and merges an array of integers to the right
 * @line: points to an array of integers
 * @size: Number of elements in array
 * Return: 1 success, 0 Fail
 */
int right_slider(int *line, size_t size)
{
	int i, j, index = size - 1;

	for (i = size - 1; i >= 0 && index >= 0; i--)
	{
		if (line[i] > 0)
		{
			if (index != i)
			{
				line[index] = line[i];
				line[i] = 0;
			}
			for (j = i - 1; j >= 0 && index >= 0; j--)
			{
				if (line[j] == line[index])
				{
					line[index] += line[j];
					line[j] = 0;
					break;
				}
			}
			index--;
		}
	}
	return (1);
}

/**
* slide_line - Reproduces the 2048 game mechanics on a single horizontal line.
* @line: Points to an array of integers containing size elements.
* @size: Number of elements in line.
* @direction: Can be either SLIDE_LEFT or SLIDE_RIGHT.
* Return: 1 upon success, or 0 upon failure.
*/
int slide_line(int *line, size_t size, int direction)
{
	if (line == NULL || size < 1 || (direction != 0 && direction != 1))
		return (0);
	if (direction == SLIDE_LEFT)
		return (left_slider(line, size));
	return (right_slider(line, size));
}
