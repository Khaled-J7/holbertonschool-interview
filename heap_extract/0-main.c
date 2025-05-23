#include <stdlib.h>
#include <stdio.h>

#include "binary_trees.h"

/*
 * The following are helper functions needed in this main file
 * You don't need them in your `heap_extract` function.
 * These functions are provided in the static library for testing purposes.
 */
heap_t *_array_to_heap(int *array, size_t size);
void binary_tree_print(const binary_tree_t *tree);
void _binary_tree_delete(binary_tree_t *tree);

/**
 * main - Entry point for testing the heap_extract function
 *
 * This main function demonstrates the heap extraction process step by step.
 * It creates a max heap from an array, then extracts the root multiple times
 * to show how the heap maintains its properties after each extraction.
 *
 * The test data includes both positive and negative numbers to ensure
 * the heap correctly handles the full range of integer values.
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
    heap_t *tree;
    int array[] = {
        79, 47, 68, 87, 84, 91, 21, 32, 34, 2,
        20, 22, 98, 1, 62, 95
    };
    size_t n = sizeof(array) / sizeof(array[0]);
    int extract;

    /* 
     * Create a max heap from the array using the helper function
     * This function is provided in the static library and builds
     * a complete binary tree that satisfies the max heap property
     */
    tree = _array_to_heap(array, n);
    if (!tree)
        return (1);

    /* Display the initial heap structure */
    printf("Initial heap:\n");
    binary_tree_print(tree);
    printf("\n");

    /* 
     * First extraction: Should return 98 (the maximum value)
     * After extraction, 95 should become the new root
     */
    extract = heap_extract(&tree);
    printf("Extracted: %d\n", extract);
    binary_tree_print(tree);
    printf("\n");

    /* 
     * Second extraction: Should return 95
     * The heap will reorganize to maintain the max heap property
     */
    extract = heap_extract(&tree);
    printf("Extracted: %d\n", extract);
    binary_tree_print(tree);
    printf("\n");

    /* 
     * Third extraction: Should return 91
     * Notice how the tree structure changes but remains a valid heap
     */
    extract = heap_extract(&tree);
    printf("Extracted: %d\n", extract);
    binary_tree_print(tree);
    printf("\n");

    /* 
     * Clean up memory - this is crucial for preventing memory leaks
     * The _binary_tree_delete function recursively frees all nodes
     */
    _binary_tree_delete(tree);
    return (0);
}