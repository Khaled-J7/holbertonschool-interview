#include "search_algos.h"

/**
 * print_array - Prints an array of integers
 * @array: The array to be printed
 * @left: The left index of the array
 * @right: The right index of the array
 *
 * Return: void
 */
void print_array(int *array, size_t left, size_t right)
{
    size_t i;

    printf("Searching in array: ");
    for (i = left; i <= right; i++)
    {
        printf("%d", array[i]);
        if (i < right)
            printf(", ");
    }
    printf("\n");
}

/**
 * binary_search_recursive - Searches recursively for a value in a sorted
 * array of integers using binary search algorithm
 * @array: Pointer to the first element of the array to search in
 * @left: The left index of the subarray
 * @right: The right index of the subarray
 * @value: The value to search for
 *
 * Return: The first index where value is located, or -1 if not found
 */
int binary_search_recursive(int *array, size_t left, size_t right, int value)
{
    size_t mid;

    /* Print the current subarray being searched */
    print_array(array, left, right);

    /* Base case: element not found */
    if (left > right)
        return (-1);

    /* Calculate the middle index */
    mid = left + (right - left) / 2;

    /* Found value, but need to check if it's the first occurrence */
    if (array[mid] == value)
    {
        /* If this is the first element or the previous element is different */
        if (mid == left || array[mid - 1] != value)
            return (mid);
        /* Otherwise, continue searching in the left half */
        return (binary_search_recursive(array, left, mid, value));
    }
    /* If value is in the left half */
    else if (array[mid] > value)
        return (binary_search_recursive(array, left, mid - 1, value));
    /* If value is in the right half */
    else
        return (binary_search_recursive(array, mid + 1, right, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * using advanced binary search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: First index where value is located, or -1 if not found or array is NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
    /* Check if array is NULL or empty */
    if (array == NULL || size == 0)
        return (-1);

    /* Call recursive binary search function */
    return (binary_search_recursive(array, 0, size - 1, value));
}
