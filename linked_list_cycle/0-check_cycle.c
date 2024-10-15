#include <stdio.h>
#include "lists.h"

int check_cycle(listint_t *list) {
    listint_t *temp = list, *adresses[1000];
    int index = 0, for_index;

    if (list == NULL){
        return (0);
    }
    while (temp->next != NULL)
    {
        for (for_index = 0; for_index < index; for_index++){
            if (adresses[for_index] == temp) {
                return (1);
            }
        }
        adresses[index] = temp;
        temp = temp->next;
        for_index = 0;
        index++;
    } 
    return (0);
}