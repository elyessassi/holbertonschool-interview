#include "slide_line.h"

/**
 * slide_line - a function that slides an array of integers to the left or the 
 *              right and merges the numbers that are idantical or contiguous
 *              or seperated by zeros
 * @line pointer that points to the first element of the array line
 * @size: size of the array line
 * @direction: direction to slide the array to 
 *             0 for left and 1 or right
 * Return: 1 for success 0 for failure
 */

int slide_line(int *line, size_t size, int direction) {
    int *tracker, temp;
    int i;
    int length = size;

    if (direction == 0) {
        tracker = line;
        for (i = 1; i < length; i++){
            if (line[i] != 0) {
                if (line[i] != *tracker) {
                    if (*tracker != 0) {
                        tracker++;
                    }
                    temp = line[i];
                    line[i] = 0;
                    *tracker = temp;
                }
                else if (line[i] == *tracker) {
                    *tracker = line[i] + *tracker;
                    line[i] = 0;
                    tracker++;
                }
            }
        }
        return (1);
    }
    else if (direction == 1)
    {
        tracker = &line[size - 1];
        for (i = length - 2; i >= 0; i--){
            if (line[i] != 0) {
                if (line[i] != *tracker) {
                    if (*tracker != 0) {
                        tracker--;
                    }
                    temp = line[i];
                    line[i] = 0;
                    *tracker = temp;
                }
                else if (line[i] == *tracker) {
                    *tracker = line[i] + *tracker;
                    line[i] = 0;
                    tracker--;
                }
            }
        }
        return (1);
    }
    else {
        return (0);
    }
}
