#include "menger.h"

/**
 * menger - draws a 2D Menger Sponge
 *
 * @level: the level of the Menger Sponge to draw
 *
 */

void menger(int level)
{
	char blk;
	int size, i, j, row, col;

	size = pow(3, level);
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size;)
		{
			row = i;
			col = j++;
			blk = '#';
			while (row > 0 || col > 0)
			{
				if (row % 3 == 1 && col % 3 == 1)
					blk = ' ';
				row = row / 3;
				col = col / 3;
			}
			printf("%c", blk);
		}
		printf("\n");
	}
}
