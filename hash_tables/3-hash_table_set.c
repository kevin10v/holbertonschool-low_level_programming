#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * create_node - Creates a new hash node with given key and value.
 * @key: The key string (non-empty).
 * @value: The value string to store.
 *
 * Return: Pointer to the new node, or NULL on failure.
 */
hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *new_node;
	char *key_copy, *val_copy;

	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
		return (NULL);

	key_copy = strdup(key);
	val_copy = strdup(value);
	if (!key_copy || !val_copy)
	{
		free(new_node);
		free(key_copy);
		free(val_copy);
		return (NULL);
	}

	new_node->key = key_copy;
	new_node->value = val_copy;
	new_node->next = NULL;

	return (new_node);
}

/**
 * hash_table_set - Adds or updates a key-value pair in the hash table.
 * @ht: The hash table.
 * @key: The key string (must not be empty).
 * @value: The value string.
 *
 * Return: 1 on success, 0 on failure.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	hash_node_t *node, *new_node;

	if (!ht || !key || *key == '\0' || !value)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);
	node = ht->array[idx];

	while (node)
	{
		if (strcmp(node->key, key) == 0)
		{
			char *new_val = strdup(value);

			if (!new_val)
				return (0);

			free(node->value);
			node->value = new_val;
			return (1);
		}
		node = node->next;
	}

	new_node = create_node(key, value);
	if (!new_node)
		return (0);

	new_node->next = ht->array[idx];
	ht->array[idx] = new_node;

	return (1);
}
