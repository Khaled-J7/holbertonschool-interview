#include "binary_trees.h"
#include <stdlib.h>

/**
 * get_heap_size - Calculate the number of nodes in the heap
 * @root: Pointer to the root node
 * 
 * Return: Number of nodes in the heap
 */
static size_t get_heap_size(heap_t *root)
{
    if (!root)
        return (0);
    
    /* Recursively count nodes in left and right subtrees, plus current node */
    return (1 + get_heap_size(root->left) + get_heap_size(root->right));
}

/**
 * get_last_node - Find the last node in level-order traversal
 * @root: Pointer to the root node
 * @index: Current index in level-order (1-based)
 * @size: Total size of the heap
 * 
 * This function finds the rightmost node in the bottom level.
 * We use the mathematical property that for a complete binary tree,
 * the last node is at position 'size' in level-order numbering.
 * 
 * Return: Pointer to the last node
 */
static heap_t *get_last_node(heap_t *root, size_t index, size_t size)
{
    if (!root || index > size)
        return (NULL);
    
    /* If we've reached the target position, this is our last node */
    if (index == size)
        return (root);
    
    /* 
     * For level-order traversal in a complete binary tree:
     * - Left child is at position 2*index
     * - Right child is at position 2*index + 1
     * We search the subtree that could contain our target
     */
    if (2 * index <= size)
    {
        heap_t *left_result = get_last_node(root->left, 2 * index, size);
        if (left_result)
            return (left_result);
    }
    
    if (2 * index + 1 <= size)
    {
        heap_t *right_result = get_last_node(root->right, 2 * index + 1, size);
        if (right_result)
            return (right_result);
    }
    
    return (NULL);
}

/**
 * heapify_down - Restore heap property by moving node down the tree
 * @node: Node to start heapifying from
 * 
 * This is the heart of maintaining the max heap property.
 * We compare the current node with its children and swap with
 * the larger child if necessary, then continue down the tree.
 */
static void heapify_down(heap_t *node)
{
    heap_t *largest = node;
    heap_t *temp;
    int temp_val;
    
    if (!node)
        return;
    
    /* Find the largest among node and its children */
    if (node->left && node->left->n > largest->n)
        largest = node->left;
    
    if (node->right && node->right->n > largest->n)
        largest = node->right;
    
    /* If the largest is not the current node, we need to swap */
    if (largest != node)
    {
        /* Swap the values (not the nodes themselves) */
        temp_val = node->n;
        node->n = largest->n;
        largest->n = temp_val;
        
        /* Continue heapifying down from the swapped position */
        heapify_down(largest);
    }
}

/**
 * heap_extract - Extract the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * 
 * This function implements the complete heap extraction algorithm:
 * 1. Handle edge cases (empty heap)
 * 2. Store the maximum value to return
 * 3. Find and remove the last node
 * 4. Replace root with last node's value
 * 5. Restore heap property through heapification
 * 
 * Return: Value that was stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
    heap_t *last_node, *parent;
    int extracted_value;
    size_t heap_size;
    
    /* Handle edge case: empty heap */
    if (!root || !*root)
        return (0);
    
    /* Store the value we're extracting (the maximum) */
    extracted_value = (*root)->n;
    
    /* Calculate heap size to find the last node */
    heap_size = get_heap_size(*root);
    
    /* Special case: only one node in the heap */
    if (heap_size == 1)
    {
        free(*root);
        *root = NULL;
        return (extracted_value);
    }
    
    /* Find the last node in level-order traversal */
    last_node = get_last_node(*root, 1, heap_size);
    if (!last_node)
        return (0);
    
    /* Replace root's value with last node's value */
    (*root)->n = last_node->n;
    
    /* Remove the last node from the tree */
    parent = last_node->parent;
    if (parent)
    {
        /* Determine if last_node is left or right child and remove it */
        if (parent->left == last_node)
            parent->left = NULL;
        else
            parent->right = NULL;
    }
    
    free(last_node);
    
    /* Restore the heap property by heapifying down from the root */
    heapify_down(*root);
    
    return (extracted_value);
}