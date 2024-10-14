#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

int check_cycle(listint_t *list) {
    listint_t *temp = list, *adresses[100];
    int index = 0, for_index;

    if (list == NULL){
        return (0);
    }
    while (temp->next != NULL)
    {
        adresses[index] = temp;
        temp = temp->next;

        for (for_index = 0; for_index < index; for_index++){
            if (adresses[for_index] == temp) {
                return (1);
            }
        }
        for_index = 0;
        index++;
    } 
    return (0);
}