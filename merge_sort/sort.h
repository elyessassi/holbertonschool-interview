#ifndef MERGE
#define MERGE

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void merge_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void merge(int *newarray, int **array, size_t sizeLeft, size_t sizeRight);


#endif // MERGE
