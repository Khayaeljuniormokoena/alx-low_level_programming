#include "lists.h"

/**
 * sum_listint - Calculate the sum of all integers in a listint_t linked list.
 * @head: A pointer to the head of the list.
 * Return: The sum of all integers in the list. If the list is empty, return 0.
 */

int sum_listint(listint_t *head)
{
	int sum = 0;

	if (head == NULL)
		return (0);

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
