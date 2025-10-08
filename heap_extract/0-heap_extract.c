#include "binary_trees.h"

int heap_extract(heap_t **root){
    int root_value, temp;
    heap_t *last_node;

    root_value = (*root)->n;

    if ((*root)->left == NULL && (*root)->right == NULL) {
        free(*root);
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
    heap_t *last_node = NULL;

    while (root != NULL){
        if (root->right)
            root = root->right;
        else if (root->left)
            root = root->left;
        else if (root->left == NULL){
            last_node = root;
            return(last_node);
        }
    }
    return(last_node);
}
// returns 1 if swaped left 2 if swaped right and 0 if not , this is done to knpw in the rebuid_heap function when there is no swaping to exit the loop
int swap (heap_t **node){
    int temp, direction;
    heap_t *max;


    if (((*node)->right) != NULL){
        if ((*node)->left >= (*node)->right){
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

    while ((*root)->left != NULL && is_swaped != 0){
        is_swaped = swap(root);
        if (is_swaped == 1)
            (*root) = (*root)->left;
        else if (is_swaped == 2)
            (*root) = (*root)->right;
    }
}

