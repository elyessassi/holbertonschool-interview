#include <stdio.h>
#include "palindrome.h"
#include <stdlib.h>
#include <string.h>

/**
 * is_palindrome - function that checks if a number is palindrome
 * @n: integer to check
 * Return: 1 if palindrome 0 if not
 */

int is_palindrome(unsigned long n)
{
	int length, i = 0;
	char str[100];

	sprintf(str, "%lu", n);
	length = calc_length(n);
	while ((i < length - 1))
	{
		if ((str[i] - 46) != (str[length - 1] - 46))
		{
			return (0);
		}
		length = length - 1;
		i++;
	}
	return (1);
}

/**
 * calc_length - function that calculates the length of an int
 * @n: the integer to calculate its length
 * Return: length
 */

int calc_length(unsigned long n)
{
	int l = 0;

	while (n % 10 != 0)
	{
		n = n / 10;
		l = l + 1;
	}
	return (l);
}
