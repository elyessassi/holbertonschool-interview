#ifndef HEAP
#define HEAP

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

typedef struct binary_tree_s heap_t;

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_print(const binary_tree_t *tree);
heap_t *heap_insert(heap_t **root, int value);
heap_t *insert_bottom(heap_t **root, binary_tree_t* newNode);
heap_t *heap_up(heap_t **child);
int get_size(heap_t *root);
int get_level(heap_t *root);
int choose(heap_t *root);
#endif