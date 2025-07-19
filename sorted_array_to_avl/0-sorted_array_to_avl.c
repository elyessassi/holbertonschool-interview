#include "binary_trees.h"

/**
 * sorted_array_to_avl - makes an avl tree from an array
 * @array: array to transform
 * @size: size of the array
 * Return: root of the avl tree
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *bst = NULL;

	if (array == NULL)
		return (NULL);
	create_tree(array, size, &bst);
	if (bst == NULL)
		printf("fama mochkla");
	return (bst);
}

/**
 * insert_bst - inserts a node in the tree
 * @bst: root to the node
 * @value: value of the node
 * Return: root of the tree
 */

avl_t *insert_bst(avl_t *bst, int value)
{
	avl_t *temp = bst, *newnode;

	newnode = malloc(sizeof(avl_t));
	if (newnode == NULL)
		return (NULL);
	newnode->n = value;
	newnode->left = newnode->right = NULL;
	if (bst == NULL)
	{
		newnode->parent = NULL;
		return (newnode);
	}
	while (1)
	{
		if (value == temp->n)
			return (bst);
		if (value > temp->n)
		{
			if (temp->right != NULL)
				temp = temp->right;
			else
			{
				newnode->parent = temp;
				temp->right = newnode;
				return (bst);
			}
		}
		if (value < temp->n)
		{
			if (temp->left != NULL)
				temp = temp->left;
			else
			{
				newnode->parent = temp;
				temp->left = newnode;
				return (bst);
			}
		}
	}
	return (bst);
}

/**
 * create_tree - chooses what value to but in the tree
 * @array: the array which we take the values from
 * @size: size of the array
 * @bst: root of the tree
 */

void create_tree(int *array, size_t size, avl_t **bst)
{
	size_t middle = (size / 2);

	if (size <= 1)
		*bst = insert_bst(*bst, *array);
	else
	{
		*bst = insert_bst(*bst, *(array + middle));
		create_tree(array, middle, bst);
		create_tree(array + middle + 1, middle - 1, bst);
	}
}
