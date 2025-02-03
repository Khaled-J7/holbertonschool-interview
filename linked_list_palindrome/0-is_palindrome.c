#include "lists.h"

/**
 * is_palindrome - checks if a linked list is a palindrome
 * @head: linked list head
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    int length = list_length(*head);  // Fix function call
    int half_length = length / 2;
    int i;
    listint_t *reversed_head, *current = *head, *current_reversed;

    if (*head == NULL || (*head)->next == NULL) // Empty list or single node is always palindrome
        return (1);

    reversed_head = *head;
    for (i = 0; i < half_length; i++)
        reversed_head = reversed_head->next;
    
    if (length % 2 != 0) // Skip middle element for odd-length lists
        reversed_head = reversed_head->next;

    reversed_head = reversed(&reversed_head);  // Fix function call
    current_reversed = reversed_head;
    current = *head;

    while (current_reversed != NULL)
    {
        if (current_reversed->n != current->n)
        {
            reversed(&reversed_head); // Restore list before returning
            return (0);
        }
        current_reversed = current_reversed->next;
        current = current->next;
    }

    reversed(&reversed_head); // Restore list before returning
    return (1);
}

/**
 * list_length - Get the length of a linked list
 * @head: linked list head
 * Return: length
 */
int list_length(listint_t *head)  // Fix function signature
{
    int i;
    listint_t *current = head;

    for (i = 0; current != NULL; i++)
        current = current->next;
    return (i);
}

/**
 * reversed - function that reverses a linked list
 * @head: double pointer to the list head
 * Return: Address of the new head
 */
listint_t *reversed(listint_t **head)
{
    listint_t *prev = NULL, *current = *head, *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    return (*head);
}
