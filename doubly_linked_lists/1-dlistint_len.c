#include "lists.h"

/**
 * dlistint_len - Returns the number of elements in a dlistint_t list
 * @h: Pointer to the head of the list
 *
 * Return: Number of elements
 */
size_t dlistint_len(const dlistint_t *h)
{
size_t count = 0;

while (h)
{
count++;
h = h->next;
}
return (count);
}
