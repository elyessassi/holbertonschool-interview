#include "lists.h"
#include <stdio.h>


listint_t *find_listint_loop(listint_t *head){
    listint_t *slow;
    listint_t *fast;

    if (head == NULL || head->next == NULL)
        return(NULL);

    slow = head->next;
    fast = head->next->next;
    
    while (slow != fast){
        slow = slow->next;
        fast = fast->next->next;
        
        if (fast == NULL)
            return(NULL);
    }

    
    slow = head;

    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return(fast);
}
