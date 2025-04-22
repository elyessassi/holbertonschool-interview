#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "binary_trees.h"

/**
 * heap_insert - a function that inserts a value into a Max Binary Heap
 * @root: double ptr to the root of the binary tree
 * @value: the value of the new node
 * Return: ptr to the new node
 */

heap_t *heap_insert(heap_t **root, int value)
{

	binary_tree_t *newNode = binary_tree_node(NULL, value);
	heap_t *result;

	if (*root == NULL)
	{
		*root = newNode;
		return (*root);
	}
	result = insert_bottom(root, newNode);

	result = heap_up(&result);

	return (result);
}

/**
 * insert_bottom - inserts the node to the bottom of the binary tree
 * @root: double ptr to the root of the binary tree
 * @newNode: ptr to the new node
 * Return: ptr to the new node (linked to the bt)
 */

heap_t *insert_bottom(heap_t **root, binary_tree_t *newNode)
{

	if ((*root)->left == NULL)
	{
		newNode->parent = *root;
		(*root)->left = newNode;
		return ((*root)->left);
	}
	if ((*root)->right == NULL)
	{
		newNode->parent = *root;
		(*root)->right = newNode;
		return ((*root)->right);
	}
	if (choose(*root) == 0)
		return (insert_bottom(&(*root)->left, newNode));
	else
		return (insert_bottom(&(*root)->right, newNode));
}

/**
 * heap_up - heapifies up the newly added node
 * @child: double ptr to the new node
 * Return: ptr to the new Node
 */

heap_t *heap_up(heap_t **child)
{
	int temp;

	while ((*child)->parent != NULL)
	{
		if ((*child)->n > (*child)->parent->n)
		{
			temp = (*child)->parent->n;
			(*child)->parent->n = (*child)->n;
			(*child)->n = temp;
		}
		else
		{
			break;
		}
		*child = (*child)->parent;
	}
	return (*child);
}

/**
 * get_size - gets the size of the binary tree (elements not edges)
 * @root: pointer to the root of the bt
 * Return: size of the bt
 */

int get_size(heap_t *root)
{
	if (root == NULL)
	{
		return (0);
	}
	return (1 + get_size(root->left) + get_size(root->right));
}

/**
 * get_level - get the level of the binary tree
 * @root: ptr to the root of the bt
 * Return: level of the bt
 */

int get_level(heap_t *root)
{
	int level = 1;

	while (root->left != NULL)
	{
		level++;
		root = root->left;
	}

	return (level);
}

/**
 * choose - chooses to go to the left or to the right of the binary tree
 * @root: ptr to the root of the binary tree
 * Return: 0 to go left 1 to go right
 */

int choose(heap_t *root)
{
	int size = get_size(root);
	int level = get_level(root);
	int supposed_nodes_per_level = (1 << (level - 1));
	int supposed_size_if_completedbt = 0;
	int i;

	for (i = 0; i < level; i++)
	{
		supposed_size_if_completedbt = supposed_size_if_completedbt + (1 << i);
	}
	if (size == supposed_size_if_completedbt)
		return (0);

	if (size < supposed_size_if_completedbt - (supposed_nodes_per_level / 2))
		return (0);
	else
		return (1);
}
