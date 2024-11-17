#include "menger.h"
#include <stdio.h>
#include <math.h>


/**
 * menger - function that displays a menger sponge
 * @level: the level of the menger sponge
 */

void menger(int level)
{
	int i, j, size;

	size = pow(3, level);
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (checkpos(i, j))
			{
				printf("#");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}


/**
 * checkpos - funtion that checks if a certain
 * coordinate is a center a cube of not
 * @x: x coordinant
 * @y: y coordinant
 * Return: 0 if center 1 if not
 */

int checkpos(int x, int y)
{
	while (x > 0 && y > 0)
		if (x % 3 == 1 && y % 3 == 1)
		{
			return (0);
		}
		else
		{
			x /= 3;
			y /= 3;
		}
	return (1);
}
