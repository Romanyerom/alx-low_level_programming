#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * hash_table_set - Adds an element to the hash table.
 * @ht: The hash table.
 * @key: The key.
 * @value: The value associated with the key.
 *
 * Return: 1 if successful, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    hash_node_t *new_node, *current;

    if (ht == NULL || key == NULL || value == NULL || *key == '\0')
        return (0);

    index = key_index((unsigned char *)key, ht->size);

    /* Check if key already exists; if yes, update the value */
    current = ht->array[index];
    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            free(current->value);  /* Free the old value */
            current->value = strdup(value); /* Duplicate the new value */
            if (current->value == NULL)
                return (0);
            return (1);
        }
        current = current->next;
    }

    /* Create a new node for the key-value pair */
    new_node = malloc(sizeof(hash_node_t));
    if (new_node == NULL)
        return (0);
    
    new_node->key = strdup(key);
    new_node->value = strdup(value);

    if (new_node->key == NULL || new_node->value == NULL)
    {
        free(new_node->key);
        free(new_node->value);
        free(new_node);
        return (0);
    }

    /* Handle collisions by adding the new node at the beginning */
    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    return (1);
}
