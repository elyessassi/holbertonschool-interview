#include <stdio.h>
#include "lists.h"


/**
 * is_palindrome - checks if a singly linked list is palindrome
 * @head: pointer to the head of the linked list
 * Return: 1 if palindrome 0 if not
 **/


int is_palindrome(listint_t **head)
{
	int array[10];
	listint_t *temp = *head;
	int iterator = 0;
	/* the loop will start iteration from the middle using this variable*/
	int index = 0;

	if (*head == NULL)
	{
		return (1);
	}
	/* this while loop is for filling the array*/
	while (temp != NULL)
	{
		array[iterator] = temp->n;
		printf("%i  ", temp->n);
		temp = temp->next;
		iterator++;
	}
	/* here I will use the iterator value as a length */
	index = iterator / 2;
	/***
	 * I will compare the number in the index to the length of the array-index-1
	 * and then i go to the next number in the array (index + 1)
	 ***/
	while (index < iterator)
	{
		if (array[index] != array[iterator - index - 1])
		{
			return (0);
		}
		else
		{
			index += 1;
		}
	}
	return (1);
}
