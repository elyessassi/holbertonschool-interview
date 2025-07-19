#include "binary_trees.h"

avl_t *sorted_array_to_avl(int *array, size_t size){
    avl_t *bst = NULL;

    if (array == NULL)
        return NULL;
    create_tree(array, size, &bst);
    if (bst == NULL) {
        printf("fama mochkla");
    }
    return(bst);
}

avl_t *insert_bst(avl_t *bst, int value){
    avl_t *temp = bst;
    avl_t *newnode;

    if (bst == NULL){
        newnode = malloc(sizeof(avl_t));
        if (newnode == NULL)
            return(NULL);
        newnode->n = value;
        newnode->left = NULL;
        newnode->right = NULL;
        newnode->parent = NULL;
        bst = newnode;
        return(bst);
    }

    while (1){
        if (value == temp->n){
            return(bst);
        }
        if (value > temp->n){
            if (temp->right != NULL)
                temp = temp->right;
            else{
                newnode = malloc(sizeof(avl_t));
                newnode->n = value;
                newnode->left = NULL;
                newnode->right = NULL;
                newnode->parent = temp;
                temp->right = newnode;
                return(bst);
            }
        }
        if (value < temp->n){
            if (temp->left != NULL)
                temp = temp->left;
            else{
                newnode = malloc(sizeof(avl_t));
                newnode->n = value;
                newnode->left = NULL;
                newnode->right = NULL;
                newnode->parent = temp;
                temp->left = newnode;
                return(bst);
            }
        }
    }
    return(bst);
}

void create_tree(int *array, size_t size, avl_t **bst){

    size_t middle = (size / 2);

    if (size <= 1){
        *bst = insert_bst(*bst, *array);
    }
    else{
        *bst = insert_bst(*bst, *(array + middle));
        create_tree(array, middle, bst);
        create_tree(array + middle + 1, middle - 1, bst);
    }
}
