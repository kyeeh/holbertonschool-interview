#include "sandpiles.h"

/**
  *sandpiles_sum - computes the sum of two sandpiles
  *@grid1: it's a sandpile
  *@grid2: it's a sandpile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, unstable = 0;
	// int grid_aux[3][3];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
			if (grid1[i][j] > 3)
				unstable = 1;
		}
	}
	if (unstable)
	{
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				grid1[i][j] = grid1[i][j] + grid2[i][j];
				if (grid1[i][j] > 3)
					unstable = 1;
			}
		}
	}
}
