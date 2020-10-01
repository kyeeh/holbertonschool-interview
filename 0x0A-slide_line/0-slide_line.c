#include "slide_line.h"

/**
* slide_line - Reproduces the 2048 game mechanics on a single horizontal line.
* @line: Points to an array of integers containing size elements.
* @size: Number of elements in line.
* @direction: Can be either SLIDE_LEFT or SLIDE_RIGHT.
* Return: 1 upon success, or 0 upon failure.
*/

int slide_line(int *line, size_t size, int direction)
{
	int i, j, index = 0;

	if (line == NULL || size < 1 || (direction != 0 && direction != 1))
		return (0);
	if (direction == SLIDE_LEFT)
	{
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
	}
	else if (direction == SLIDE_RIGHT)
	{
		index = size - 1;
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
	}
	return (1);
}
