#include "binary_trees.h"
#include <stdio.h>

int heap_extract(heap_t **root){
    int root_value, temp;
    heap_t *last_node;

    
    if (*root == NULL){
        return(0);
    }
    root_value = (*root)->n;

    if ((*root)->left == NULL && (*root)->right == NULL) {
        free(*root);
        *root = NULL;
        return(root_value);
    }
    last_node = get_last_node(*root);
    // swapting the values of last node with the root
    temp = (*root)->n;
    (*root)->n = last_node->n;
    last_node->n = temp;


    //freeing the last node
    if (last_node->parent->left == last_node)
        last_node->parent->left = NULL;

    if (last_node->parent->right == last_node)
        last_node->parent->right = NULL;
    free(last_node);

    rebuild_heap(root);

    return(root_value);

}

heap_t *get_last_node(heap_t *root){
    if (root->left == NULL && root->right == NULL)
        return(root);
    else if (root->right == NULL)
        return(root->left);
    

    int h_left = getHeight(root->left);
    int h_right = getHeight(root->right);

    if (h_left > h_right)
        return(get_last_node(root->left));
    else
        return(get_last_node(root->right));
}
// returns 1 if swaped left 2 if swaped right and 0 if not , this is done to know in the rebuid_heap function when there is no swaping to exit the loop
int swap (heap_t **node){
    int temp, direction;
    heap_t *max;


    if (((*node)->right) != NULL){
        if ((*node)->left->n >= (*node)->right->n){
            max = (*node)->left;
            direction = 1;
        }
        else {
            max = (*node)->right;
            direction = 2;
        }
    }
    else {
        max = (*node)->left;
        direction = 1;
    }
    if (max->n > (*node)->n){
        temp = max->n;
        max->n = (*node)->n ;
        (*node)->n = temp;
        return(direction);
    }
    return(0);

}

void rebuild_heap(heap_t **root){
    int is_swaped = 1;
    heap_t *current = *root;

    while (current->left != NULL && is_swaped != 0){
        is_swaped = swap(&current);
        if (is_swaped == 1)
            current = current->left;
        else if (is_swaped == 2)
            current = current->right;
    }
    
    // heap_t *temp = last_node->parent;
    // int tempVal = last_node->n, storeVal;
    // while(temp != NULL){
    //     storeVal = temp->n;
    //     temp->n = tempVal;
    //     tempVal = storeVal;
    //     temp = temp->parent;
    // }
    // root = root;
    // last_node->n = RootVal; 


    
}

int getHeight(heap_t *root){
    int height = 0;
    while (root != NULL){
        height += 1;
        root = root->left;
    }
    return(height);
}