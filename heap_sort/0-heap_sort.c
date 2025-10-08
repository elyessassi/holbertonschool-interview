#include "sort.h"

/**
 * heap_sort - heap sort algorithm
 * @array: the array to sort
 * @size: size of the array
 */

void heap_sort(int *array, size_t size)
{
	int temp, i, j, maxidx, isIdentical;

	if (array == NULL || size < 2)
		return;
	isIdentical = checkIfIdentical(array, size);
	if (isIdentical == 1)
		return;
	for (i = size - 1; i >= 0; i--)
	{
		for (j = i; j >= 0; j--)
		{
			if ((j * 2 + 1) <= i) /**  if it has left child*/
			{
				if ((j * 2 + 2) <= i) /** check if it has right child */
				{
					if (*(array + (j * 2 + 2)) > *(array + (j * 2 + 1)))
						maxidx = (j * 2 + 2);
					else
						maxidx = (j * 2 + 1);
				}
				else
					maxidx = (j * 2 + 1);
				if (*(array + maxidx) > *(array + j))
				{
					temp = *(array + maxidx);
					*(array + maxidx) = *(array + j);
					*(array + j) = temp;
					print_array(array, size);
					FixChangedElement(maxidx, &array, i, size); /** heapify new elem down*/
				}
			}
		}
		if (*(array + i) != *array) /**substituting last elem with first elem */
		{
			temp = *(array + i);
			*(array + i) = *array;
			*array = temp;
			print_array(array, size);
		}
	}
}

/**
 * FixChangedElement - heapifies changed elem to the bottom
 * @index: the index of the element we are heapifying
 * @array: the array we are sorting
 * @LastIdx: the index that we shouldnt pass
 * @size: the size of the array
 * Return: 1 if changed 0 if not
 */

void FixChangedElement(int index, int **array, int LastIdx, size_t size)
{
	int MaxChildIdx, temp;

	while ((index * 2) + 1 <= LastIdx)
	{
		if ((index * 2) + 2 <= LastIdx)
		{
			if (*(*(array) + (index * 2) + 2) > *(*(array) + (index * 2) + 1))
				MaxChildIdx = ((index * 2) + 2);
			else
				MaxChildIdx = ((index * 2) + 1);
		}
		else
			MaxChildIdx = ((index * 2) + 1);
		if (*(*(array) + index) < *(*(array) + MaxChildIdx))
		{
			temp = *(*(array) + MaxChildIdx);
			*(*(array) + MaxChildIdx) = *(*(array) + index);
			*(*(array) + index) = temp;
			print_array(*array, size);
		}
		index = MaxChildIdx;
	}
}



/** Created for checker */

/**
* checkIfIdentical - checking of all elems are identical in an array
* @array: the array to check
* @size: size of the array
* Return: 1 if identical 0 if not
*/

int checkIfIdentical(int *array, size_t size)
{
	int isIdentical = 1, valueToCheck = *array;
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (*(array + i) != valueToCheck)
			isIdentical = 0;
	}
	if (isIdentical == 1)
	{
		for (i = 0; i < size - 1; i++)
		{
			print_array(array, size);
		}
	}
	return (isIdentical);
}
