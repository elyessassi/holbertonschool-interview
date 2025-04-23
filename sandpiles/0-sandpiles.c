#include <stdio.h>
#include "sandpiles.h"

/**
 * sandpiles_sum - sums sandpiles
 * @grid1: sandpile 1
 * @grid2: sandpile 2
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, a, b, has_toppling_cpt = 15, has_toppling[18];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];
	}
	while (has_toppling_cpt > 0)
	{
		if (check_toppling(grid1) == 1)
		{
			printf("=\n");
			my_print_grid(grid1);
		}
		has_toppling_cpt = 0;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					has_toppling[has_toppling_cpt] = i;
					has_toppling[has_toppling_cpt + 1] = j;
					has_toppling_cpt = has_toppling_cpt + 2;
				}
			}
		}
		for (i = 0; i < has_toppling_cpt; i = i + 2)
		{
			j = i + 1;
			a = has_toppling[i];
			b = has_toppling[j];
			(a < 2) ? grid1[a + 1][b] = grid1[a + 1][b] + 1 : grid1[a + 1][b];
			(a > 0) ? grid1[a - 1][b] = grid1[a - 1][b] + 1 : grid1[a - 1][b];
			(b < 2) ? grid1[a][b + 1] = grid1[a][b + 1] + 1 : grid1[a][b + 1];
			(b > 0) ? grid1[a][b - 1] = grid1[a][b - 1] + 1 : grid1[a][b - 1];
			grid1[a][b] = grid1[a][b] - 4;
		}
	}
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 */

void my_print_grid(int grid[3][3])
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
 * check_toppling - checks if there are toppling in the sandpile
 * @grid: sandpile to check
 * Return: 1 if the are topplings 0 if not
 */

int check_toppling(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (1);
		}
	}
	return (0);
}
