#include "sort.h"

// I didint create 2 array because the task requires that i can call malloc only once

void merge_sort(int *array, size_t size){
    size_t mid;
    int *newarray;
    size_t i;

    if (size <= 1 || array == NULL){
        return;
    }
    mid = size / 2;
    newarray = malloc(sizeof(int) * size);
    if (newarray == NULL)
        return;
    for (i = 0; i < size; i++){
        *(newarray + i) = *(array + i);
    }
    merge_sort(newarray, mid);
    merge_sort(newarray + mid, size - mid);
    merge(newarray, &array, mid, size - mid);
}

void merge(int *newarray, int **array, size_t sizeLeft, size_t sizeRight){
    size_t i = 0, j = sizeLeft, k = 0;

    printf("Merging...\n");
    printf("[left]: ");
    print_array(newarray, sizeLeft);
    printf("[right]: ");
    print_array(newarray + sizeLeft, sizeRight);
    while(i < sizeLeft && j < sizeLeft + sizeRight){
        if (*(newarray + i) <= *(newarray + j)){
            *(*array + k) = *(newarray + i);
            k = k + 1;
            i = i + 1;
        }
        else {
            *(*array + k) = *(newarray + j);
            k = k + 1;
            j = j + 1;
        }
    }
    while (i < sizeLeft){
        *(*array + k) = *(newarray + i);
        k = k + 1;
        i = i + 1;
    }
    while (j < sizeLeft + sizeRight){

        *(*array + k) = *(newarray + j);
        k = k + 1;
        j = j + 1;
    }
    printf("[Done]: ");
    print_array(*array, sizeLeft + sizeRight);
    free(newarray);
}

