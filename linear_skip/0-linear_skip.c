#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 *
 * Return: pointer to the first node where value is located, or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *express, *current;

    /* Check if list is NULL */
    if (!list)
        return (NULL);

    /* Initialize pointers */
    current = list;
    express = list->express;

    /* Use express lane to find the range where value might be */
    while (express && express->n < value)
    {
        printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
        current = express;
        express = express->express;
    }

    /* Handle case where we reach the end of express lane */
    if (!express)
    {
        /* Find the last node in the list */
        express = current;
        while (express->next)
            express = express->next;
    }

    /* Print the range where value is located */
    printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
    printf("Value found between indexes [%lu] and [%lu]\n",
           current->index, express->index);

    /* Linear search in the found range */
    while (current && current->index <= express->index)
    {
        printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
        if (current->n == value)
            return (current);
        current = current->next;
    }

    /* Value not found */
    return (NULL);
}
