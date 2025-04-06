#include "binary_trees.h"

/**
 * create_avl_tree - Recursively builds an AVL tree from a sorted array
 *
 * @array: Pointer to the first element of the array
 * @start: Starting index of the current subarray
 * @end: Ending index of the current subarray
 * @parent: Pointer to the parent node
 *
 * Return: Pointer to the root of the created AVL tree, NULL on failure
 */
avl_t *create_avl_tree(int *array, int start, int end, avl_t *parent)
{
	avl_t *new_node;
	int mid;

	/* Base case: if start index is greater than end index */
	if (start > end)
		return (NULL);

	/* Calculate middle index */
	mid = start + (end - start) / 2;

	/* Create new node with the middle element */
	new_node = malloc(sizeof(avl_t));
	if (new_node == NULL)
		return (NULL);

	/* Initialize the new node */
	new_node->n = array[mid];
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	/* Recursively build left subtree */
	new_node->left = create_avl_tree(array, start, mid - 1, new_node);

	/* Recursively build right subtree */
	new_node->right = create_avl_tree(array, mid + 1, end, new_node);

	return (new_node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 *
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	/* Check for NULL array or empty array */
	if (array == NULL || size == 0)
		return (NULL);

	/* Call helper function to create the AVL tree */
	return (create_avl_tree(array, 0, size - 1, NULL));
}
