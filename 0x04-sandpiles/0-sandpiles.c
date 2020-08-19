#include "sandpiles.h"

/**
  *print_grid - print_grid
  *@grid: it's a sandpile
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
  *unstable - computes the sum of two grids and check unstable values
  *@grid1: it's a grid
  *@grid2: it's a grid
  *
  * Return: 1 if unstable, 0 otherwise.
 */
int unstable(int grid1[3][3], int grid2[3][3])
{
	int i, j, u = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
			grid2[i][j] = 0;
			if (grid1[i][j] > 3)
				u = 1;
		}
	}
	return (u);
}

/**
  *sandrop - computes the sum of two sandpiles
  *@grid1: it's a sandpile
  *@grid2: it's a sandpile
 */
void sandrop(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (j = 0; j < 3; j++)
	{
		for (i = 0; i < 3; i++)
		{
			if (grid1[i][j] > 3)
			{
				grid1[i][j] -= 4;
				if (i > 0)
					grid2[i - 1][j] += 1;
				if (i < 2)
					grid2[i + 1][j] += 1;
				if (j > 0)
					grid2[i][j - 1] += 1;
				if (j < 2)
					grid1[i][j + 1] += 1;
			}
		}
	}
}

/**
  *sandpiles_sum - computes the sum of two sandpiles
  *@grid1: it's a sandpile
  *@grid2: it's a sandpile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	while (unstable(grid1, grid2))
	{
		printf("=\n");
		print_grid(grid1);
		sandrop(grid1, grid2);
	}
}
