#include <stdio.h>
#include "lists.h"


int is_palindrome(listint_t **head) {
    int array[10];
    listint_t *temp = *head;
    int iterator = 0;
    /* the loop will start iteration from the middle 
     using this variable*/
    int index = 0;


    if (*head == NULL) {
        return (1);
    }
    /* this while loop is for filling the array*/
    while (temp != NULL) {
        array[iterator] = temp->n;
        temp = temp->next;
        iterator++;
    }
    /* here i will use the iterator value as a length */
    index = iterator / 2;
    /* in this while loop i will compare the number in the middle to the length of 
        the array - index - 1*/
    while (index < iterator) {
        if (array[index] != array[iterator - index - 1]){
            return (0);
        }
        else {
            index += 1;
        }
    }
    return (1);
}
