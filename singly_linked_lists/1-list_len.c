#include "lists.h"

/**
 * list_len - Returns the number of elements in a list_t list
 * @h: Pointer to the first node of the list
 * Return: Number of elements in the list
 */
size_t list_len(const list_t *h)
{
size_t count = 0;

while (h)
{
h = h->next;
count++;
}
return (count);
}
