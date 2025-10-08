#ifndef SORT
#define SORT

#include <stdlib.h>
#include <stdio.h>


void heap_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void FixChangedElement(int indexOfElem, int **array, int LastIdx, size_t size);
int checkIfIdentical(int *array, size_t size);

#endif
