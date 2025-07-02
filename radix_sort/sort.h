#ifndef SORT_H
#define SORT_H

#include <stdlib.h> /* For size_t, malloc, free */

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of thelist
 */
typedef struct listint_s
{
  const int n;
  struct listint_s *prev;
  struct listint_s *next;
} listint_t;

/* Provided Print Function */
void print_array(const int *array, size_t size);

/* Radix Sort Function Prototype */
void radix_sort(int *array, size_t size);

#endif /* SORT_H */
