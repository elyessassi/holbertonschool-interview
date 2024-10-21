#include <stdio.h>
#include "palindrome.h"
#include <stdlib.h>

/**
 * is_palindrome - function that checks if a number is palindrome
 * @n: integer to check
 * Return: 1 if palindrome 0 if not
 */

int is_palindrome(unsigned long n)
{
	unsigned long r = 0, n_copy;

	n_copy = n;
	while (n_copy != 0)
	{
		r = r * 10 + (n_copy % 10);
		n_copy = n_copy / 10;
	}

	if (r == n)
		return (1);
	else
		return (0);
}

