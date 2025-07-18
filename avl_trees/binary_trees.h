#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Basic Binary Tree Structure */
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

/* AVL Tree Typedef */
typedef struct binary_tree_s avl_t;

/* Function for printing the tree (provided) */
void binary_tree_print(const binary_tree_t *);

/* Task 0: Is AVL */
int binary_tree_is_avl(const binary_tree_t *tree);

#endif /* _BINARY_TREES_H_ */
