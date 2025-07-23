#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - Inserts a node at a given index.
 * @h: Double pointer to the head of the list.
 * @idx: The index where the new node should be inserted.
 * @n: The data to insert.
 *
 * Return: Address of the new node, or NULL on failure.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h,
                                      unsigned int idx,
                                      int n)
{
	dlistint_t *new_node, *current = *h;
	unsigned int i = 0;

	if (h == NULL)
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(h, n));

	while (current != NULL && i < idx - 1)
	{
		current = current->next;
		i++;
	}

	if (current == NULL)
		return (NULL);

	if (current->next == NULL)
		return (add_dnodeint_end(h, n));

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = current;
	new_node->next = current->next;
	current->next->prev = new_node;
	current->next = new_node;

	return (new_node);
}
