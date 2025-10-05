#include "sort.h"

// max is for the child that has the maximum value

void heap_sort(int *array, size_t size)
{
    int temp, i, j, maxidx;

    if (size < 2)
        return;

    if (array == NULL)
        return;

    for (i = size - 1; i >= 0; i--)
    {
        for (j = i; j >= 0; j--)
        {
            // if it has left child
            if ((j * 2 + 1) <= i)
            {
                // check if it has right child
                if ((j * 2 + 2) <= i)
                {
                    if (*(array + (j * 2 + 2)) > *(array + (j * 2 + 1)))
                    {

                        maxidx = (j * 2 + 2);
                    }
                    else
                    {
                        maxidx = (j * 2 + 1);
                    }
                }
                else
                    maxidx = (j * 2 + 1);
                if (*(array + maxidx) > *(array + j))
                {
                    temp = *(array + maxidx);
                    *(array + maxidx) = *(array + j);
                    *(array + j) = temp;
                    print_array(array, size);
                    // this is for checking if the new changed child must be heapfied
                    FixChangedElement(maxidx, &array, i, size);
                }
                if (*(array + maxidx) == *(array + j)){
                    print_array(array, size);
                }
            }   
        }
        // substituting the last element with the first element
        if (*(array + i) != *array)
        {
            temp = *(array + i);
            *(array + i) = *array;
            *array = temp;
            print_array(array, size);
        }
    }
}

int FixChangedElement(int indexOfElem, int **array, int LastIdx, size_t size)
{
    int MaxChildIdx, temp, isChanged = 0;

    while ((indexOfElem * 2) + 1 <= LastIdx)
    {
        if ((indexOfElem * 2) + 2 <= LastIdx)
        {
            if (*(*(array) + (indexOfElem * 2) + 2) > *(*(array) + (indexOfElem * 2) + 1))
                MaxChildIdx = ((indexOfElem * 2) + 2);
            else
                MaxChildIdx = ((indexOfElem * 2) + 1);
        }
        else
        {
            MaxChildIdx = ((indexOfElem * 2) + 1);
        }
        if (*(*(array) + indexOfElem) < *(*(array) + MaxChildIdx))
        {
            isChanged = 1;
            temp = *(*(array) + MaxChildIdx);
            *(*(array) + MaxChildIdx) = *(*(array) + indexOfElem);
            *(*(array) + indexOfElem) = temp;
            print_array(*array, size);
        }
        indexOfElem = MaxChildIdx;
    }
    return (isChanged);
}