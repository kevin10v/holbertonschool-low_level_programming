#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - Adds a new node at the beginning of a list_t list
 * @head: Double pointer to the head of the list
 * @str: String to duplicate and store in the new node
 * Return: Address of the new element, or NULL if it failed
 */
list_t *add_node(list_t **head, const char *str)
{
list_t *new_node;
char *dup_str;
unsigned int len = 0;

new_node = malloc(sizeof(list_t));
if (new_node == NULL)
return (NULL);

dup_str = strdup(str);
if (dup_str == NULL)
{
free(new_node);
return (NULL);
}

while (str[len])
len++;

new_node->str = dup_str;
new_node->len = len;
new_node->next = *head;
*head = new_node;

return (new_node);
}
