#include "holberton.h"

/**
 * main - main function
 * @argc: number of arguments
 * @argv: array that consists of the arguments
 * Return: 1 for success 0 for failure
 */

int main(int argc, char *argv[])
{
	char *result, *start, *end, *num1, *num2;
	int res_len, size1, size2;

	if (argc != 3)
		exitFunc();
	num1 = argv[1];
	num2 = argv[2];
	if (*num1 == '0' || *num2 == '0'){
		printf("0\n");
		exit(0);
	}
	if (checkIfNum(*num2) == 0)
		exitFunc();
	if (checkIfNum(*num1) == 0)
		exitFunc();
	size1 = mystrlen(num1);
	size2 = mystrlen(num2);
	if (((*num1 - '0') * (*num2 - '0')) >= 10) /**array with size of the result*/
	{
		res_len = (size1 + size2);
		result = malloc(sizeof(char) * res_len + 1);
	}
	else
	{
		res_len = (size1 + size2 - 1);
		result = malloc(sizeof(char) * res_len + 1);
	}
	start = result;
	num2 = num2 + size2 - 1;
	if (checkIfNum(*num2) == 0)
		exitFunc();
	zerosArray(&result, res_len);
	end = result + res_len;		/** points to the last digit result */
	result = getMul(num1, num2, size1, size2, result, start, end);
	print_string(result);
	free(result);
}

/**
 * mystrlen - function that gets the length of a string
 * @mystring: string to get its length
 * Return: the length
 */

int mystrlen(char *mystring)
{
	int length = 0;

	while (*mystring != '\0')
	{
		length = length + 1;
		mystring = mystring + 1;
	}
	return (length);
}

/**
 * print_string - prints given array
 * @str: array to print
 */

void print_string(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str = str + 1;
	}
	_putchar('\n');
}

/**
 * checkIfNum - checks if a character represents a number
 * @chr: the character to check
 * Return: 1 if it is a number 0 if not
 */

int checkIfNum(char chr)
{
	if (chr < 48 || chr > 57)
		return (0);
	return (1);
}

/**
 * exitFunc - function that is called in case of an error
 */

void exitFunc(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * zerosArray - fills the array with zeros
 * @array: the array to modify
 * @len: length of the array
 */

void zerosArray(char **array, int len)
{
	char *temp;
	int i;

	temp = *array;
	for (i = 0; i < len; i++)
	{
		*temp = '0';
		temp = temp + 1;
	}
}

/**
 * getMul - gives the result of the multiplication in form of an array
 * @n1: argument 1
 * @n2: argument 2
 * @s1: size of arg1
 * @s2: size of arg2
 * @res: the array to fill
 * @s: the start of the array
 * @e: the end of the array
 * Return: the array
 * variables consist of one letter to make the line shorter
 */

char *getMul(char *n1, char *n2, int s1, int s2, char *res, char *s, char *e)
{
	int i, j, first_digit, second_digit, digit1, digit2, product, mult_cpt = 1;

	for (i = 0; i < s2; i++) /**  main logic */
	{
		n1 = n1 + s1 - 1;
		if (checkIfNum(*n1) == 0){
			exitFunc();
		}
		res = e - mult_cpt;
		for (j = 0; j < s1; j++)
		{
			product = (*n1 - '0') * (*n2 - '0');
			if (product > 9)
			{
				first_digit = (product % 10) + '0';
				second_digit = (product / 10) + '0';
			}
			else
			{
				first_digit = product + '0';
				second_digit = '0';
			}
			if (((*res - '0') + (first_digit - '0')) >= 10)
			{
				digit1 = (((*res - '0') + (first_digit - '0')) % 10) + '0';
				digit2 = (((*res - '0') + (first_digit - '0')) / 10) + '0';
				*res = digit1;
				*(res - 1) = (*(res - 1) - '0') + (digit2 - '0') + '0';
			}
			else
				*res = (*res - '0') + (first_digit - '0') + '0';
			if (res != s)
			{
				*(res - 1) = (*(res - 1) - '0') + (second_digit - '0') + '0';
				res = res - 1;
			}
			if (j < s1 - 1){
				n1 = n1 - 1;
			} 
		}
		if (checkIfNum(*n2) == 0)
			exitFunc();
		n2 = n2 - 1;
		mult_cpt += 1;
	}
	return (res);
}
