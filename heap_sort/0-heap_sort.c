#include "sort.h"

// max is for the child that has the maximum value

void heap_sort(int *array, size_t size){
    int temp, i, j, maxidx;

    if (size < 2)
        return;

    if (array == NULL)
        return;


    for (i = size - 1; i >= 0 ; i--){
        for (j = i; j >= 0; j--){
            // if it has left child
            if ((j * 2 + 1) <= i){
                // check if it has right child
                if ((j * 2 + 2) <= i){
                    if (*(array + (j * 2 + 2)) > *(array + (j * 2 + 1))){

                        maxidx = (j * 2 + 2);
                    }
                    else{
                        maxidx = (j * 2 + 1);
                    }
                }
                else
                    maxidx = (j * 2 + 1);
                if (*(array + maxidx) > *(array + j)){
                    temp = *(array + maxidx);
                    *(array + maxidx) = *(array + j);
                    *(array + j) = temp;
                    print_array(array, size);
                    // this is for checking if the new changed child must be heapfied
                    while((maxidx * 2 + 1) <= j){
                        if ((maxidx * 2 + 1) <= j){
                            if ((j * 2 + 2) > (j * 2 + 1))
                                maxidx = (j * 2 + 2);
                            else
                                maxidx = (j * 2 + 1);
                        }
                        else
                            maxidx = (j * 2 + 1);
                        print_array(array, size);

                        if (*(array + maxidx) > *(array + j)){
                            temp = *(array + maxidx);
                            *(array + maxidx) = *(array + j);
                            *(array + j) = temp;
                            print_array(array, size);
                        }
                    }
                }

            }
        }
        // substituting the last element with the first element
        temp = *(array + i);
        *(array + i) = *array;
        *array = temp;
        print_array(array, size);
    }
}


