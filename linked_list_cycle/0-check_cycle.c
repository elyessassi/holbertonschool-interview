#include <stdio.h>
#include "lists.h"

int check_cycle(listint_t *list) {
    listint_t *steps2 = list, *steps1 = list; 

    if (list == NULL){
        return (0);
    }
    while (steps2 != NULL && steps2->next != NULL) {
        steps2 = steps2->next->next;
        steps1 = steps1->next;
        if (steps1 == steps2){
            return (1);
        }
    }
    return (0);
}