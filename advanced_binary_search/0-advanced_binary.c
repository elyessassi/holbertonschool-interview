#include "search_algos.h"

/**
* advanced_binary - main function
* @array: array to search in
* @size: size of the array
* @value: value to search for
* Return: return value of get_value
*/

int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);
	return (get_value(array, value, 0, size - 1));
}

/**
* print_array - function to print the array
* @array: array to print
* @start: index where we start printing
* @end: index where we end printing
*
*/

void print_array(int *array, int start, int end)
{
	int i;

	printf("Searching in array: ");
	printf("%d", *(array + start));
	for (i = start + 1; i < end + 1; i++)
	{
		printf(", %d", *(array + i));
	}
	printf("\n");
}

/**
* get_value - searchs for the value recursivly
* @array: array to search in
* @value: value to search for
* @start: starting point
* @end: ending point
* Return: index if the value is found -1 if it is not found
*/

int get_value(int *array, int value, int start, int end)
{
	int mid = (start + end) / 2;

	if (start >= end)
	{
		if (*(array + mid) == value)
			return (mid);
		print_array(array, start, end);
		return (-1);
	}
	print_array(array, start, end);
	if (*(array + mid) >= value)
		return (get_value(array, value, start, mid));
	return (get_value(array, value, mid + 1, end));
}


