#ifndef AVL
#define AVL

#include <stdio.h>
#include <stdlib.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};
typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s avl_t;

void binary_tree_print(const binary_tree_t *);
avl_t *sorted_array_to_avl(int *array, size_t size);
avl_t *insert_bst(avl_t *bst, int value);
void create_tree(int *array, size_t size, avl_t **bst);





#endif
