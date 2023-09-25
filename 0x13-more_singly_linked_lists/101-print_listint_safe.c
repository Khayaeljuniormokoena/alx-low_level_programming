#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list safely.
 * @head: Pointer to the head of the linked list.
 * Return: Number of nodes in the list.
 */

size_t print_listint_safe(const listint_t *head)
{
    const listint_t *current = head;
    size_t node_count = 0;

    while (current != NULL)
    {
        printf("[%p] %d\n", (void *)current, current->n);

        /* Move to the next node */
        current = current->next;
        node_count++;

        /* Check if we have looped back to a previously visited node */
        if (current == head)
        {
            printf("-> [%p] %d\n", (void *)current, current->n);
            break;
        }
    }

    return (node_count);
}
