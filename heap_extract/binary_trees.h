#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
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

/* Basic Binary Tree type definition */
typedef struct binary_tree_s binary_tree_t;

/* Max Binary Heap type definition - same structure, different semantic meaning */
typedef struct binary_tree_s heap_t;

/* Function prototypes */

/* Main heap extraction function - this is what you're implementing */
int heap_extract(heap_t **root);

/* Helper functions that might be provided in the static library */
heap_t *_array_to_heap(int *array, size_t size);
void binary_tree_print(const binary_tree_t *tree);
void _binary_tree_delete(binary_tree_t *tree);

/* Additional utility functions that might be useful */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_height(const binary_tree_t *tree);

#endif /* BINARY_TREES_H */