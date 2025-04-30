#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * heapify - Maintains the max heap property
 * @array: The array to heapify
 * @size: The current size of the heap
 * @i: The index of the root of the subtree to heapify
 * @original_size: The original size of the array (for printing)
 */
void heapify(int *array, size_t size, size_t i, size_t original_size)
{
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != i)
    {
        swap(&array[i], &array[largest]);
        print_array(array, original_size);
        heapify(array, size, largest, original_size);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
    int i;

    if (array == NULL || size < 2)
        return;

    /* Build max heap */
    for (i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i, size);

    /* Extract elements from the heap one by one */
    for (i = size - 1; i > 0; i--)
    {
        swap(&array[0], &array[i]);
        print_array(array, size);
        heapify(array, i, 0, size);
    }
}
