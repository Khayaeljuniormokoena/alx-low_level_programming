#include <stdef.h>
#include "lists.h"

/**
 * list_len - returns the number of elements in a linked list_t list.
 * @h: Pointer to the head of the linked list
 *
 * Return: The number of elements (nodes) in the list.
 */

size_t list_len(const list_t *h)
{
	size_t k = 0;

	while (h)
	{
		k++;
		h = h->next;
	}
	return (k);
}
