#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_get - Retrieves a value associated with a key.
 * @ht: The hash table.
 * @key: The key to search for.
 *
 * Return: The value associated with the key,
 *         or NULL if key couldn't be found.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int idx;
	hash_node_t *node;

	if (!ht || !key || *key == '\0')
		return (NULL);

	idx = key_index((const unsigned char *)key, ht->size);
	node = ht->array[idx];

	while (node)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}

	return (NULL);
}
