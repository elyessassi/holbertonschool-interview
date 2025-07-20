#include "search.h"

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *temp, *temp2;

	temp = list;
	if (list->n == value)
		return (list);
	while (temp != NULL)
	{
		if (temp->express == NULL)
		{
			temp2 = temp;
			while (temp2->next != NULL)
				temp2 = temp2->next;
			print_value_found(temp->index, temp2->index);
			break;
		}
		if (temp->express->n == value)
		{
			print_value_checked(temp->express->index, temp->express->n);
			return (temp->express);
		}

		if (temp->express->n > value)
		{
			print_value_checked(temp->express->index, temp->express->n);
			print_value_found(temp->index, temp->express->index);
			break;
		}
		temp = temp->express;
		print_value_checked(temp->index, temp->n);
	}
	while (temp != NULL)
	{
		print_value_checked(temp->index, temp->n);
		if (temp->n == value)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

void print_value_checked(size_t idx, int value)
{
	printf("Value checked at index [%ld] = [%d]\n", idx, value);
}

void print_value_found(size_t idx1, size_t idx2)
{
	printf("Value found between indexes [%ld] and [%ld]\n", idx1, idx2);
}
