#include <stdio.h>
#include "lists.h"

int main(void)
{
    listint_t *head = NULL;
    listint_t *node;

    /* Create a linked list: 1 -> 2 -> 3 -> 4 -> 5 */
    add_nodeint(&head, 5);
    add_nodeint(&head, 4);
    add_nodeint(&head, 3);
    add_nodeint(&head, 2);
    add_nodeint(&head, 1);

    /* Check for cycle (no cycle) */
    printf("Linked list has %s\n", check_cycle(head) ? "a cycle" : "no cycle");

    /* Create a cycle: 5 -> 3 */
    node = head;
    while (node->next != NULL)
        node = node->next;
    node->next = head->next->next;

    /* Check for cycle (cycle exists) */
    printf("Linked list has %s\n", check_cycle(head) ? "a cycle" : "no cycle");

    /* Free the list (avoid memory leaks) */
    free_listint(head);

    return (0);
}