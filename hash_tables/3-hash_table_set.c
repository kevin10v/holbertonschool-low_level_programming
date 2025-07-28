#include "hash_tables.h"
#include <string.h>
#include <stdlib.h>

/**
 * hash_table_set - Adds or updates a key/value pair in the hash table
 * @ht: The hash table
 * @key: The key (non-empty string)
 * @value: The value to store (duplicated)
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *node;
	unsigned long int index;
	char *val_copy;

	if (!ht || !key || !*key || !value)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node)
	{
		if (strcmp(node->key, key) == 0)
		{
			val_copy = strdup(value);
			if (!val_copy)
				return (0);
			free(node->value);
			node->value = val_copy;
			return (1);
		}
		node = node->next;
	}

	return (create_and_insert_node(ht, key, value, index));
}
