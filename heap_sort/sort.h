#ifndef SORT
#define SORT

#include <stdlib.h>
#include <stdio.h>

struct node
{
    int n;
    struct node *left;
    struct node *right;
    struct node *parent;
};
typedef struct node node_t;

void heap_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
int FixChangedElement(int indexOfElem, int **array, int LastIdx);

#endif
