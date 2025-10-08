#include "search_algos.h"

int advanced_binary(int *array, size_t size, int value){
    if (array == NULL){
        return(-1);
    }
    return(get_value(array, value, 0, size - 1));
}

void print_array(int *array, int start, int end){
    int i;
    printf("Searching in array: ");
    printf("%d", *(array + start));
    for (i = start + 1; i < end + 1; i++){
        printf(", %d", *(array + i));
    }
    printf("\n");
}

int get_value(int *array, int value, int start, int end){
    int mid = (start + end) / 2;

    if (start >= end){
        if (*(array + mid) == value)
            return(mid);
        print_array(array, start, end);
        return(-1);
    }
    print_array(array, start, end);
    if (*(array + mid) >= value)
        return(get_value(array, value, start, mid));
    return(get_value(array, value, mid + 1, end));
}


